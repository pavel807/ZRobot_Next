use axum::{
    extract::WebSocketUpgrade,
    response::IntoResponse,
    routing::{get, post},
    Json, Router,
};
use parking_lot::RwLock;
use pyo3::prelude::*;
use std::sync::Arc;
use tower_http::services::ServeDir;

pub struct AppState {
    pub latest_state: serde_json::Value,
    pub latest_frame: Option<Vec<u8>>,
}

impl Default for AppState {
    fn default() -> Self {
        Self {
            latest_state: serde_json::json!({
                "video": {"fps": 0},
                "detection": {"target": "-", "found": false},
                "motor": {"enabled": true},
                "obstacle_avoidance": {"enabled": true},
                "lidar": {"connected": false},
                "settings": {},
            }),
            latest_frame: None,
        }
    }
}

fn create_router(state: Arc<RwLock<AppState>>) -> Router {
    let static_dir = ServeDir::new("web_interface/src/static");

    Router::new()
        .route("/", get(serve_index))
        .route("/api/state", get(handle_state))
        .route("/api/status", get(handle_status))
        .route("/api/settings", post(handle_settings))
        .route("/api/motor", post(handle_motor))
        .route("/ws", get(websocket_handler))
        .nest_service("/static", static_dir)
        .with_state(state)
}

async fn serve_index() -> impl IntoResponse {
    axum::response::Html(include_str!("static/index.html"))
}

async fn handle_state(state: axum::extract::State<Arc<RwLock<AppState>>>) -> impl IntoResponse {
    Json(state.read().latest_state.clone())
}

async fn handle_settings(
    state: axum::extract::State<Arc<RwLock<AppState>>>,
    Json(payload): Json<serde_json::Value>,
) -> impl IntoResponse {
    let mut state_guard = state.write();
    if let Some(obj) = payload.as_object() {
        for (key, value) in obj {
            state_guard.latest_state["settings"][key] = value.clone();
        }
    }
    Json(serde_json::json!({"success": true}))
}

async fn handle_motor(
    state: axum::extract::State<Arc<RwLock<AppState>>>,
    Json(payload): Json<serde_json::Value>,
) -> impl IntoResponse {
    let mut state_guard = state.write();
    if payload.get("emergency").is_some() {
        state_guard.latest_state["motor"]["current_command"] = serde_json::json!({"linear": 0.0, "angular": 0.0});
        return Json(serde_json::json!({"success": true, "action": "stop"}));
    }
    let linear = payload.get("linear").and_then(|v| v.as_f64()).unwrap_or(0.0);
    let angular = payload.get("angular").and_then(|v| v.as_f64()).unwrap_or(0.0);
    state_guard.latest_state["motor"]["current_command"] = serde_json::json!({"linear": linear, "angular": angular});
    Json(serde_json::json!({"success": true}))
}

async fn handle_status(state: axum::extract::State<Arc<RwLock<AppState>>>) -> impl IntoResponse {
    let state_guard = state.read();
    Json(state_guard.latest_state.get("detection").cloned().unwrap_or(serde_json::Value::Null))
}

async fn websocket_handler(
    ws: WebSocketUpgrade,
    state: axum::extract::State<Arc<RwLock<AppState>>>,
) -> impl IntoResponse {
    ws.on_upgrade(move |socket| async {})
}

#[pyclass]
pub struct WebServer {
    state: Arc<RwLock<AppState>>,
}

#[pymethods]
impl WebServer {
    #[new]
    fn new_() -> PyResult<Self> {
        Ok(Self { state: Arc::new(RwLock::new(AppState::default())) })
    }

    fn update_state(&self, json_data: String) {
        if let Ok(data) = serde_json::from_str(&json_data) {
            self.state.write().latest_state = data;
        }
    }

    fn run_blocking(&self, host: String, port: u32) {
        let rt = tokio::runtime::Builder::new_current_thread().enable_all().build().unwrap();
        let state = self.state.clone();
        let addr = format!("{}:{}", host, port);

        rt.block_on(async move {
            let app = create_router(state);
            if let Ok(listener) = tokio::net::TcpListener::bind(&addr).await {
                let _ = axum::serve(listener, app).await;
            }
        });
    }
}

#[pymodule]
fn zrobot_web(m: &Bound<'_, PyModule>) -> PyResult<()> {
    m.add_class::<WebServer>()?;
    Ok(())
}