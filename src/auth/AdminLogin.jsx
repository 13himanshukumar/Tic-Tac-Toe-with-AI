export default function AdminLogin({ setView }) {
  return (
    <div className="container mt-5 text-center">
      <h2>Admin Login</h2>

      <input className="form-control mb-2" placeholder="Admin Email" />
      <input
        className="form-control mb-2"
        placeholder="Password"
        type="password"
      />

      <button
        className="btn btn-danger m-2"
        onClick={() => setView("PRODUCTS")}
      >
        Login
      </button>

      <button className="btn btn-link" onClick={() => setView("PUBLIC")}>
        ← Back
      </button>
    </div>
  );
}
