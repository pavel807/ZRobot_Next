use pyo3::prelude::*;
use std::collections::VecDeque;

#[pyclass]
pub struct SingleObjectTracker {
    #[pyo3(get, set)]
    pub id: i32,
    #[pyo3(get, set)]
    pub label: i32,
    #[pyo3(get, set)]
    pub class_name: String,
    #[pyo3(get, set)]
    pub age: i32,
    #[pyo3(get, set)]
    pub consecutive_misses: i32,
    #[pyo3(get, set)]
    pub is_confirmed: bool,
    history: VecDeque<(i32, i32, i32, i32)>,
    confidence_history: VecDeque<f64>,
    x: [f64; 6],
    P: [[f64; 6]; 6],
    last_bbox: (i32, i32, i32, i32),
    last_confidence: f64,
}

#[pymethods]
impl SingleObjectTracker {
    #[new]
    fn new(
        track_id: i32,
        label: i32,
        class_name: String,
        bbox: (i32, i32, i32, i32),
        confidence: f64,
    ) -> Self {
        let mut tracker = Self {
            id: track_id,
            label,
            class_name,
            age: 0,
            consecutive_misses: 0,
            is_confirmed: false,
            history: VecDeque::new(),
            confidence_history: VecDeque::new(),
            x: [0.0; 6],
            P: [
                [1.0, 0.0, 0.0, 0.0, 0.0, 0.0],
                [0.0, 1.0, 0.0, 0.0, 0.0, 0.0],
                [0.0, 0.0, 1.0, 0.0, 0.0, 0.0],
                [0.0, 0.0, 0.0, 1.0, 0.0, 0.0],
                [0.0, 0.0, 0.0, 0.0, 1.0, 0.0],
                [0.0, 0.0, 0.0, 0.0, 0.0, 1.0],
            ],
            last_bbox: bbox,
            last_confidence: confidence,
        };

        let (x, y, w, h) = bbox;
        let cx = x as f64 + w as f64 / 2.0;
        let cy = y as f64 + h as f64 / 2.0;
        tracker.x[0] = cx;
        tracker.x[1] = cy;
        tracker.x[4] = w as f64;
        tracker.x[5] = h as f64;

        tracker.history.push_back(bbox);
        tracker.confidence_history.push_back(confidence);

        tracker
    }

    fn predict(&mut self, dt: f64) -> (i32, i32, i32, i32) {
        let mut new_x = [0.0; 6];
        for i in 0..6 {
            new_x[i] = self.x[i];
        }
        new_x[0] = self.x[0] + self.x[2] * dt;
        new_x[1] = self.x[1] + self.x[3] * dt;

        let q = 0.1;
        for i in 0..6 {
            self.P[i][i] += q;
        }

        self.x = new_x;

        let cx = self.x[0];
        let cy = self.x[1];
        let w = self.x[4];
        let h = self.x[5];

        let x = (cx - w / 2.0) as i32;
        let y = (cy - h / 2.0) as i32;

        (x, y, w as i32, h as i32)
    }

    fn update(&mut self, bbox: (i32, i32, i32, i32), confidence: f64) {
        let (x, y, w, h) = bbox;
        let cx = x as f64 + w as f64 / 2.0;
        let cy = y as f64 + h as f64 / 2.0;

        let z = [cx, cy, w as f64, h as f64];

        let H: [[f64; 6]; 4] = [
            [1.0, 0.0, 0.0, 0.0, 0.0, 0.0],
            [0.0, 1.0, 0.0, 0.0, 0.0, 0.0],
            [0.0, 0.0, 0.0, 0.0, 1.0, 0.0],
            [0.0, 0.0, 0.0, 0.0, 0.0, 1.0],
        ];

        let R: [[f64; 4]; 4] = [
            [0.5, 0.0, 0.0, 0.0],
            [0.0, 0.5, 0.0, 0.0],
            [0.0, 0.0, 0.5, 0.0],
            [0.0, 0.0, 0.0, 0.5],
        ];

        let mut S: [[f64; 4]; 4] = [[0.0; 4]; 4];
        for i in 0..4 {
            for j in 0..4 {
                for k in 0..6 {
                    S[i][j] += H[i][k] * self.P[k][j];
                }
                S[i][j] += R[i][j];
            }
        }

        let S_inv = matrix_inverse_4x4(&S);
        if S_inv.is_none() {
            return;
        }
        let S_inv = S_inv.unwrap();

        let mut K: [[f64; 6]; 4] = [[0.0; 6]; 4];
        for i in 0..6 {
            for j in 0..4 {
                K[i][j] = 0.0;
                for k in 0..4 {
                    K[i][j] += self.P[i][k] * H[k][j];
                }
                for k in 0..4 {
                    K[i][j] += S_inv[j][k] * K[i][k];
                }
            }
        }

        let mut z_pred = [0.0; 4];
        for i in 0..4 {
            for j in 0..6 {
                z_pred[i] += H[i][j] * self.x[j];
            }
        }

        let mut innovation = [0.0; 4];
        for i in 0..4 {
            innovation[i] = z[i] - z_pred[i];
        }

        for i in 0..6 {
            for j in 0..4 {
                self.x[i] += K[i][j] * innovation[j];
            }
        }

        for i in 0..6 {
            for j in 0..6 {
                let mut sum = 0.0;
                for k in 0..4 {
                    sum += K[i][k] * H[k][j];
                }
                self.P[i][j] -= sum * self.P[i][j];
            }
        }

        self.history.push_back(bbox);
        if self.history.len() > 30 {
            self.history.pop_front();
        }

        self.confidence_history.push_back(confidence);
        if self.confidence_history.len() > 30 {
            self.confidence_history.pop_front();
        }

        self.last_bbox = bbox;
        self.last_confidence = confidence;

        self.age += 1;
        self.consecutive_misses = 0;

        if self.age >= 3 {
            self.is_confirmed = true;
        }
    }

    fn mark_missed(&mut self, confidence_decay: f64) {
        self.consecutive_misses += 1;
        if let Some(&last_conf) = self.confidence_history.back() {
            let decayed = last_conf * confidence_decay;
            self.confidence_history.push_back(decayed);
            if self.confidence_history.len() > 30 {
                self.confidence_history.pop_front();
            }
        }
    }

    fn get_average_confidence(&self) -> f64 {
        if self.confidence_history.is_empty() {
            return 0.0;
        }
        let sum: f64 = self.confidence_history.iter().sum();
        sum / self.confidence_history.len() as f64
    }

    fn get_velocity(&self) -> (f64, f64) {
        if self.history.len() < 2 {
            return (0.0, 0.0);
        }

        let curr = self.history.iter().rev().next().unwrap();
        let prev = self.history.iter().rev().nth(1).unwrap();

        let curr_cx = curr.0 as f64 + curr.2 as f64 / 2.0;
        let curr_cy = curr.1 as f64 + curr.3 as f64 / 2.0;
        let prev_cx = prev.0 as f64 + prev.2 as f64 / 2.0;
        let prev_cy = prev.1 as f64 + prev.3 as f64 / 2.0;

        (curr_cx - prev_cx, curr_cy - prev_cy)
    }
}

fn compute_iou(bbox1: (i32, i32, i32, i32), bbox2: (i32, i32, i32, i32)) -> f64 {
    let (x1, y1, w1, h1) = bbox1;
    let (x2, y2, w2, h2) = bbox2;

    let x1_min = x1;
    let y1_min = y1;
    let x1_max = x1 + w1;
    let y1_max = y1 + h1;

    let x2_min = x2;
    let y2_min = y2;
    let x2_max = x2 + w2;
    let y2_max = y2 + h2;

    let inter_x_min = x1_min.max(x2_min);
    let inter_y_min = y1_min.max(y2_min);
    let inter_x_max = x1_max.min(x2_max);
    let inter_y_max = y1_max.min(y2_max);

    let inter_w = (inter_x_max - inter_x_min).max(0);
    let inter_h = (inter_y_max - inter_y_min).max(0);
    let intersection = inter_w * inter_h;

    let area1 = w1 * h1;
    let area2 = w2 * h2;
    let union = area1 + area2 - intersection;

    if union > 0 {
        intersection as f64 / union as f64
    } else {
        0.0
    }
}

fn matrix_inverse_4x4(m: &[[f64; 4]; 4]) -> Option<[[f64; 4]; 4]> {
    let det = m[0][0] * (m[1][1] * m[2][2] * m[3][3] - m[1][2] * m[2][3] * m[3][1])
        - m[0][1] * (m[1][0] * m[2][2] * m[3][3] - m[1][2] * m[2][3] * m[3][0])
        + m[0][2] * (m[1][0] * m[2][1] * m[3][3] - m[1][1] * m[2][3] * m[3][0])
        - m[0][3] * (m[1][0] * m[2][1] * m[3][2] - m[1][1] * m[2][2] * m[3][0]);

    if det.abs() < 1e-10 {
        return None;
    }

    let inv_det = 1.0 / det;
    let mut result = [[0.0; 4]; 4];

    result[0][0] = (m[1][1] * m[2][2] * m[3][3] - m[1][2] * m[2][3] * m[3][1]) * inv_det;
    result[0][1] = (m[0][2] * m[2][3] * m[3][1] - m[0][1] * m[2][2] * m[3][3]) * inv_det;
    result[0][2] = (m[0][1] * m[1][2] * m[3][3] - m[0][2] * m[1][1] * m[3][3]) * inv_det;
    result[0][3] = (m[0][2] * m[1][1] * m[2][3] - m[0][1] * m[1][2] * m[2][3]) * inv_det;
    result[1][0] = (m[1][2] * m[2][3] * m[3][0] - m[1][0] * m[2][2] * m[3][3]) * inv_det;
    result[1][1] = (m[0][0] * m[2][2] * m[3][3] - m[0][2] * m[2][3] * m[3][0]) * inv_det;
    result[1][2] = (m[0][2] * m[1][0] * m[3][3] - m[0][0] * m[1][2] * m[3][3]) * inv_det;
    result[1][3] = (m[0][0] * m[1][2] * m[2][3] - m[0][2] * m[1][0] * m[2][3]) * inv_det;
    result[2][0] = (m[1][0] * m[2][1] * m[3][3] - m[1][1] * m[2][3] * m[3][0]) * inv_det;
    result[2][1] = (m[0][1] * m[2][3] * m[3][0] - m[0][0] * m[2][1] * m[3][3]) * inv_det;
    result[2][2] = (m[0][0] * m[1][1] * m[3][3] - m[0][1] * m[1][0] * m[3][3]) * inv_det;
    result[2][3] = (m[0][1] * m[1][0] * m[2][3] - m[0][0] * m[1][1] * m[2][3]) * inv_det;
    result[3][0] = (m[1][1] * m[2][2] * m[3][0] - m[1][0] * m[2][1] * m[3][2]) * inv_det;
    result[3][1] = (m[0][0] * m[2][1] * m[3][2] - m[0][1] * m[2][2] * m[3][0]) * inv_det;
    result[3][2] = (m[0][1] * m[1][0] * m[3][2] - m[0][0] * m[1][1] * m[3][2]) * inv_det;
    result[3][3] = (m[0][0] * m[1][1] * m[2][2] - m[0][1] * m[1][0] * m[2][2]) * inv_det;

    Some(result)
}

#[pyclass]
pub struct IoUTracker {
    #[pyo3(get, set)]
    pub iou_threshold: f64,
    #[pyo3(get, set)]
    pub max_consecutive_misses: i32,
    #[pyo3(get, set)]
    pub confidence_decay: f64,
    tracks: Vec<SingleObjectTracker>,
    next_track_id: i32,
}

#[pymethods]
impl IoUTracker {
    #[new]
    fn new(iou_threshold: f64, max_consecutive_misses: i32, confidence_decay: f64) -> Self {
        Self {
            iou_threshold,
            max_consecutive_misses,
            confidence_decay,
            tracks: Vec::new(),
            next_track_id: 0,
        }
    }

    fn update(
        &mut self,
        detections: Vec<(i32, i32, i32, i32)>,
        labels: Vec<i32>,
        class_names: Vec<String>,
        confidences: Vec<f64>,
    ) -> Vec<SingleObjectTracker> {
        for track in &mut self.tracks {
            track.mark_missed(self.confidence_decay);
        }

        let n_tracks = self.tracks.len();
        let n_detections = detections.len();

        if n_tracks == 0 && n_detections == 0 {
            return vec![];
        }

        let mut cost_matrix: Vec<Vec<f64>> = vec![vec![0.0; n_detections]; n_tracks];

        for i in 0..n_tracks {
            let pred_bbox = self.tracks[i].predict(0.033);
            for j in 0..n_detections {
                if self.tracks[i].label != labels[j] {
                    cost_matrix[i][j] = 0.0;
                } else {
                    cost_matrix[i][j] = compute_iou(pred_bbox, detections[j]);
                }
            }
        }

        let mut matched_tracks = vec![false; n_tracks];
        let mut matched_detections = vec![false; n_detections];
        let mut matches: Vec<(usize, usize)> = Vec::new();

        let mut sorted_costs: Vec<(f64, usize, usize)> = Vec::new();
        for i in 0..n_tracks {
            for j in 0..n_detections {
                if cost_matrix[i][j] > self.iou_threshold {
                    sorted_costs.push((cost_matrix[i][j], i, j));
                }
            }
        }

        sorted_costs.sort_by(|a, b| b.0.partial_cmp(&a.0).unwrap());

        for (iou, ti, di) in sorted_costs {
            if !matched_tracks[ti] && !matched_detections[di] {
                matches.push((ti, di));
                matched_tracks[ti] = true;
                matched_detections[di] = true;
            }
        }

        for (ti, di) in &matches {
            self.tracks[*ti].update(detections[*di], confidences[*di]);
        }

        for j in 0..n_detections {
            if !matched_detections[j] {
                let new_track = SingleObjectTracker::new(
                    self.next_track_id,
                    labels[j],
                    class_names[j].clone(),
                    detections[j],
                    confidences[j],
                );
                self.tracks.push(new_track);
                self.next_track_id += 1;
            }
        }

        self.tracks
            .retain(|t| t.consecutive_misses <= self.max_consecutive_misses);

        self.tracks.clone()
    }

    fn get_active_count(&self) -> i32 {
        self.tracks.len() as i32
    }

    fn clear(&mut self) {
        self.tracks.clear();
        self.next_track_id = 0;
    }
}
