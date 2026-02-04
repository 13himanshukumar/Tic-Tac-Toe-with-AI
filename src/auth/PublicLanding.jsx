export default function PublicLanding({ setView }) {
  return (
    <div className="vh-100 d-flex justify-content-center align-items-center">
      <div className="text-center">
        <h1>Retail Portal</h1>
        <p>Select Role</p>

        <button
          className="btn btn-primary m-2"
          onClick={() => setView("USER_LOGIN")}
        >
          User
        </button>

        <button
          className="btn btn-dark m-2"
          onClick={() => setView("ADMIN_LOGIN")}
        >
          Admin
        </button>
      </div>
    </div>
  );
}
