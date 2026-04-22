use pyo3::prelude::*;

mod kalman;
mod iou_tracker;

pub use kalman::MultiTargetCAKF;
pub use iou_tracker::IoUTracker;

#[pymodule]
fn rust_tracker(m: &PyModule) -> PyResult<()> {
    m.add_class::<MultiTargetCAKF>()?;
    m.add_class::<IoUTracker>()?;
    Ok(())
}