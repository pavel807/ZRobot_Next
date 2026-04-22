use nalgebra::{Matrix2, Matrix6, SMatrix, SVector, Vector2, Vector6};
use pyo3::prelude::*;

const STATE_DIM: usize = 6;
const MEAS_DIM: usize = 2;

type StateMatrix = SMatrix<f64, STATE_DIM, STATE_DIM>;
type MeasMatrix = SMatrix<f64, MEAS_DIM, STATE_DIM>;
type StateVector = SVector<f64, STATE_DIM>;
type MeasVector = SVector<f64, MEAS_DIM>;

#[pyclass]
pub struct ConstantAccelerationKalmanFilter {
    x: StateVector,
    P: StateMatrix,
    F: StateMatrix,
    Q: StateMatrix,
    H: MeasMatrix,
    R: Matrix2<f64>,
    dt: f64,
    latency: f64,
    mahalanobis_threshold: f64,
    adaptive_enabled: bool,
    adaptation_threshold: f64,
    adaptation_factor: f64,
    base_q: f64,
    current_q: f64,
    last_innovation_norm: f64,
    initialized: bool,
    last_timestamp: Option<f64>,
}

#[pymethods]
impl ConstantAccelerationKalmanFilter {
    #[new]
    fn new(
        dt: f64,
        process_noise_acc: f64,
        measurement_noise: f64,
        mahalanobis_threshold: f64,
        latency_ms: f64,
        adaptive_enabled: bool,
        adaptation_threshold: f64,
        adaptation_factor: f64,
    ) -> Self {
        let mut kf = Self {
            x: StateVector::zeros(),
            P: StateMatrix::identity() * 500.0,
            F: StateMatrix::identity(),
            Q: StateMatrix::zeros(),
            H: MeasMatrix::zeros(),
            R: Matrix2::identity() * (measurement_noise * measurement_noise),
            dt,
            latency: latency_ms / 1000.0,
            mahalanobis_threshold,
            adaptive_enabled,
            adaptation_threshold,
            adaptation_factor,
            base_q: process_noise_acc,
            current_q: process_noise_acc,
            last_innovation_norm: 0.0,
            initialized: false,
            last_timestamp: None,
        };
        kf.init_matrices(process_noise_acc);
        kf
    }
}

impl ConstantAccelerationKalmanFilter {
    fn init_matrices(&mut self, q_acc: f64) {
        let dt = self.dt;
        let dt2 = dt * dt;
        let dt3 = dt2 * dt;
        let dt4 = dt3 * dt;

        self.F = StateMatrix::identity();
        self.F[(0, 2)] = dt;
        self.F[(0, 4)] = 0.5 * dt2;
        self.F[(1, 3)] = dt;
        self.F[(1, 5)] = 0.5 * dt2;
        self.F[(2, 4)] = dt;
        self.F[(3, 5)] = dt;

        self.H = MeasMatrix::zeros();
        self.H[(0, 0)] = 1.0;
        self.H[(1, 1)] = 1.0;

        self.Q = StateMatrix::zeros();
        self.Q[(0, 0)] = dt4 / 4.0 * q_acc;
        self.Q[(0, 2)] = dt3 / 2.0 * q_acc;
        self.Q[(0, 4)] = dt2 / 2.0 * q_acc;
        self.Q[(1, 1)] = dt4 / 4.0 * q_acc;
        self.Q[(1, 3)] = dt3 / 2.0 * q_acc;
        self.Q[(1, 5)] = dt2 / 2.0 * q_acc;
        self.Q[(2, 0)] = dt3 / 2.0 * q_acc;
        self.Q[(2, 2)] = dt2 * q_acc;
        self.Q[(2, 4)] = dt * q_acc;
        self.Q[(3, 1)] = dt3 / 2.0 * q_acc;
        self.Q[(3, 3)] = dt2 * q_acc;
        self.Q[(3, 5)] = dt * q_acc;
        self.Q[(4, 0)] = dt2 / 2.0 * q_acc;
        self.Q[(4, 2)] = dt * q_acc;
        self.Q[(4, 4)] = q_acc;
        self.Q[(5, 1)] = dt2 / 2.0 * q_acc;
        self.Q[(5, 3)] = dt * q_acc;
        self.Q[(5, 5)] = q_acc;
    }

    fn recompute_matrices(&mut self, dt: f64) {
        let dt2 = dt * dt;
        let dt3 = dt2 * dt;
        let dt4 = dt3 * dt;
        let q = self.current_q;

        self.F = StateMatrix::identity();
        self.F[(0, 2)] = dt;
        self.F[(0, 4)] = 0.5 * dt2;
        self.F[(1, 3)] = dt;
        self.F[(1, 5)] = 0.5 * dt2;
        self.F[(2, 4)] = dt;
        self.F[(3, 5)] = dt;

        self.Q = StateMatrix::zeros();
        self.Q[(0, 0)] = dt4 / 4.0 * q;
        self.Q[(0, 2)] = dt3 / 2.0 * q;
        self.Q[(0, 4)] = dt2 / 2.0 * q;
        self.Q[(1, 1)] = dt4 / 4.0 * q;
        self.Q[(1, 3)] = dt3 / 2.0 * q;
        self.Q[(1, 5)] = dt2 / 2.0 * q;
        self.Q[(2, 0)] = dt3 / 2.0 * q;
        self.Q[(2, 2)] = dt2 * q;
        self.Q[(2, 4)] = dt * q;
        self.Q[(3, 1)] = dt3 / 2.0 * q;
        self.Q[(3, 3)] = dt2 * q;
        self.Q[(3, 5)] = dt * q;
        self.Q[(4, 0)] = dt2 / 2.0 * q;
        self.Q[(4, 2)] = dt * q;
        self.Q[(4, 4)] = q;
        self.Q[(5, 1)] = dt2 / 2.0 * q;
        self.Q[(5, 3)] = dt * q;
        self.Q[(5, 5)] = q;
    }

    pub fn predict(&mut self, timestamp: Option<f64>) -> (f64, f64) {
        if let (Some(ts), Some(last_ts)) = (timestamp, self.last_timestamp) {
            let dt = ts - last_ts;
            if dt > 0.001 {
                self.recompute_matrices(dt);
            }
        }

        self.x = self.F * self.x;
        self.P = &self.F * &self.P * self.F.transpose() + &self.Q;

        if let Some(ts) = timestamp {
            self.last_timestamp = Some(ts);
        }

        (self.x[0], self.x[1])
    }

    pub fn update(&mut self, measurement: (f64, f64), timestamp: Option<f64>) -> (f64, f64) {
        let z = Vector2::new(measurement.0, measurement.1);

        if !self.initialized {
            self.x[0] = measurement.0;
            self.x[1] = measurement.1;
            self.initialized = true;
            if let Some(ts) = timestamp {
                self.last_timestamp = Some(ts);
            }
            return measurement;
        }

        if let (Some(ts), Some(last_ts)) = (timestamp, self.last_timestamp) {
            let dt = ts - last_ts;
            if dt > 0.001 {
                self.recompute_matrices(dt);
                self.x = &self.F * &self.x;
                self.P = &self.F * &self.P * self.F.transpose() + &self.Q;
            }
        }

        let predicted_meas = &self.H * &self.x;
        let innovation = z - predicted_meas;

        let S = &self.H * &self.P * self.H.transpose() + &self.R;
        let S_inv = S.try_inverse().unwrap_or(Matrix2::zeros());

        let mahal_sq = innovation.transpose() * S_inv * innovation;

        if mahal_sq > self.mahalanobis_threshold.powi(2) {
            self.reset_to_measurement(measurement);
            if let Some(ts) = timestamp {
                self.last_timestamp = Some(ts);
            }
            return (self.x[0], self.x[1]);
        }

        let K = &self.P * &self.H.transpose() * S_inv;

        self.x = &self.x + K * innovation;
        self.P = (StateMatrix::identity() - K * &self.H) * &self.P;

        if self.adaptive_enabled {
            self.last_innovation_norm = mahal_sq.sqrt();
            self.adapt_process_noise();
        }

        if let Some(ts) = timestamp {
            self.last_timestamp = Some(ts);
        }

        (self.x[0], self.x[1])
    }

    fn adapt_process_noise(&mut self) {
        if self.last_innovation_norm > self.adaptation_threshold {
            self.current_q = (self.current_q * self.adaptation_factor).min(self.base_q * 10.0);
        } else {
            self.current_q = (self.current_q / self.adaptation_factor).max(self.base_q);
        }

        let dt = self.dt;
        let dt2 = dt * dt;
        let dt3 = dt2 * dt;
        let dt4 = dt3 * dt;
        let q = self.current_q;

        self.Q[(0, 0)] = dt4 / 4.0 * q;
        self.Q[(0, 2)] = dt3 / 2.0 * q;
        self.Q[(0, 4)] = dt2 / 2.0 * q;
        self.Q[(1, 1)] = dt4 / 4.0 * q;
        self.Q[(1, 3)] = dt3 / 2.0 * q;
        self.Q[(1, 5)] = dt2 / 2.0 * q;
        self.Q[(2, 0)] = dt3 / 2.0 * q;
        self.Q[(2, 2)] = dt2 * q;
        self.Q[(2, 4)] = dt * q;
    }

    fn reset_to_measurement(&mut self, measurement: (f64, f64)) {
        self.x[0] = measurement.0;
        self.x[1] = measurement.1;
        self.P = StateMatrix::identity() * 10.0;
    }

    pub fn get_extrapolated_position(&self, latency_sec: Option<f64>) -> (f64, f64) {
        if !self.initialized {
            return (0.0, 0.0);
        }

        let dt = latency_sec.unwrap_or(self.latency);
        if dt <= 0.0 {
            return (self.x[0], self.x[1]);
        }

        let mut F_ext = StateMatrix::identity();
        F_ext[(0, 2)] = dt;
        F_ext[(0, 4)] = 0.5 * dt * dt;
        F_ext[(1, 3)] = dt;
        F_ext[(1, 5)] = 0.5 * dt * dt;
        F_ext[(2, 4)] = dt;
        F_ext[(3, 5)] = dt;

        let extrapolated = F_ext * &self.x;
        (extrapolated[0], extrapolated[1])
    }

    pub fn get_velocity(&self) -> (f64, f64) {
        if !self.initialized {
            return (0.0, 0.0);
        }
        (self.x[2], self.x[3])
    }

    pub fn get_acceleration(&self) -> (f64, f64) {
        if !self.initialized {
            return (0.0, 0.0);
        }
        (self.x[4], self.x[5])
    }

    pub fn reset(&mut self) {
        self.x = StateVector::zeros();
        self.P = StateMatrix::identity() * 500.0;
        self.initialized = false;
        self.last_timestamp = None;
    }
}

#[pyclass]
pub struct MultiTargetCAKF {
    dt: f64,
    process_noise_acc: f64,
    measurement_noise: f64,
    mahalanobis_threshold: f64,
    latency_ms: f64,
    max_tracks: usize,
    track_timeout: f64,
    iou_threshold: f64,
    filters: Vec<ConstantAccelerationKalmanFilter>,
    timestamps: Vec<f64>,
    class_ids: Vec<i32>,
    confidences: Vec<f64>,
    next_id: usize,
}

#[pymethods]
impl MultiTargetCAKF {
    #[new]
    fn new(
        dt: f64,
        process_noise_acc: f64,
        measurement_noise: f64,
        mahalanobis_threshold: f64,
        latency_ms: f64,
        max_tracks: usize,
        track_timeout: f64,
        iou_threshold: f64,
    ) -> Self {
        Self {
            dt,
            process_noise_acc,
            measurement_noise,
            mahalanobis_threshold,
            latency_ms,
            max_tracks,
            track_timeout,
            iou_threshold,
            filters: Vec::new(),
            timestamps: Vec::new(),
            class_ids: Vec::new(),
            confidences: Vec::new(),
            next_id: 0,
        }
    }

    pub fn predict(&mut self, timestamp: f64) {
        for kf in &mut self.filters {
            kf.predict(Some(timestamp));
        }
    }

    pub fn update(&mut self, detections: Vec<PyObject>, timestamp: f64) -> PyResult<Py<PyDict>> {
        let gil = Python::acquire_gil();
        let py = gil.python();

        self.predict(timestamp);

        let mut det_centers: Vec<(f64, f64)> = Vec::new();
        let mut det_data: Vec<Py<PyTuple>> = Vec::new();

        for det in &detections {
            let dict: &PyDict = det.extract(py)?;
            let center: &PyTuple = dict.get_item("center")?.unwrap().extract()?;
            let cx: f64 = center.get_item(0)?.extract()?;
            let cy: f64 = center.get_item(1)?.extract()?;
            det_centers.push((cx, cy));
            det_data.push(det);
        }

        let n_tracks = self.filters.len();
        let n_dets = det_centers.len();
        let mut matched_track_ids: Vec<bool> = vec![false; n_tracks];
        let mut matched_det_ids: Vec<bool> = vec![false; n_dets];

        if n_tracks > 0 && n_dets > 0 {
            let mut cost_matrix: Vec<Vec<f64>> = vec![vec![f64::INFINITY; n_dets]; n_tracks];

            for i in 0..n_tracks {
                let kf = &self.filters[i];
                let (pred_cx, pred_cy) = kf.get_extrapolated_position();

                for j in 0..n_dets {
                    let (cx, cy) = det_centers[j];
                    let dx = cx - pred_cx;
                    let dy = cy - pred_cy;

                    let S = &kf.P.fixed_view::<2, 2>(0, 0).into_owned() + kf.R.clone();
                    let S_inv = S.try_inverse().unwrap_or(Matrix2::zeros());

                    let mahal_sq = (dx * dx * S_inv[(0, 0)])
                        + (2.0 * dx * dy * S_inv[(0, 1)])
                        + (dy * dy * S_inv[(1, 1)]);

                    cost_matrix[i][j] = mahal_sq;
                }
            }

            loop {
                let mut min_cost = f64::INFINITY;
                let mut min_i = 0;
                let mut min_j = 0;
                let mut found = false;

                for i in 0..n_tracks {
                    for j in 0..n_dets {
                        if !matched_track_ids[i]
                            && !matched_det_ids[j]
                            && cost_matrix[i][j] < min_cost
                        {
                            min_cost = cost_matrix[i][j];
                            min_i = i;
                            min_j = j;
                            found = true;
                        }
                    }
                }

                if !found || min_cost > self.mahalanobis_threshold.powi(2) {
                    break;
                }

                matched_track_ids[min_i] = true;
                matched_det_ids[min_j] = true;

                let det: &PyDict = det_data[min_j].extract(py)?;
                let center: &PyTuple = det.get_item("center")?.unwrap().extract()?;
                let cx: f64 = center.get_item(0)?.extract()?;
                let cy: f64 = center.get_item(1)?.extract()?;

                self.filters[min_i].update((cx, cy), Some(timestamp));
                self.timestamps[min_i] = timestamp;
                self.class_ids[min_j] = det.get_item("class_id")?.unwrap().extract::<i32>(py)?;
                self.confidences[min_j] =
                    det.get_item("confidence")?.unwrap().extract::<f64>(py)?;
            }
        }

        for j in 0..n_dets {
            if !matched_det_ids[j] && self.filters.len() < self.max_tracks {
                let det: &PyDict = det_data[j].extract(py)?;
                let center: &PyTuple = det.get_item("center")?.unwrap().extract()?;
                let cx: f64 = center.get_item(0)?.extract()?;
                let cy: f64 = center.get_item(1)?.extract()?;
                let cls_id: i32 = det.get_item("class_id")?.unwrap().extract::<i32>(py)?;
                let conf: f64 = det.get_item("confidence")?.unwrap().extract::<f64>(py)?;

                let mut kf = ConstantAccelerationKalmanFilter::new(
                    self.dt,
                    self.process_noise_acc,
                    self.measurement_noise,
                    self.mahalanobis_threshold,
                    self.latency_ms,
                    true,
                    2.0,
                    1.5,
                );
                kf.update((cx, cy), Some(timestamp));

                self.filters.push(kf);
                self.timestamps.push(timestamp);
                self.class_ids.push(cls_id);
                self.confidences.push(conf);
            }
        }

        let current_time = timestamp;
        let mut to_remove: Vec<usize> = Vec::new();
        for (i, ts) in self.timestamps.iter().enumerate() {
            if current_time - ts > self.track_timeout {
                to_remove.push(i);
            }
        }
        for i in to_remove.into_iter().rev() {
            self.filters.remove(i);
            self.timestamps.remove(i);
            self.class_ids.remove(i);
            self.confidences.remove(i);
        }

        let result = PyDict::new(py);
        for (i, kf) in self.filters.iter().enumerate() {
            if !kf.initialized {
                continue;
            }
            let (ext_cx, ext_cy) = kf.get_extrapolated_position();
            let cx = kf.x[0];
            let cy = kf.x[1];
            let velocity = kf.get_velocity();
            let class_id = self.class_ids[i] as i32;
            let confidence = self.confidences[i];

            let track_dict = PyDict::new(py);
            track_dict.set_item("center", (cx, cy))?;
            track_dict.set_item("extrapolated_center", (ext_cx, ext_cy))?;
            track_dict.set_item("velocity", velocity)?;
            track_dict.set_item("class_id", class_id)?;
            track_dict.set_item("confidence", confidence)?;

            result.set_item(i as i64, track_dict)?;
        }

        Ok(result.into())
    }
}
