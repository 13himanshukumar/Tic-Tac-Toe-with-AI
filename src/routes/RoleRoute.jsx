import { Navigate, Outlet } from "react-router-dom";

export default function RoleRoute({ role }) {
  const userRole = localStorage.getItem("role");

  if (userRole !== role) {
    return <Navigate to="/" replace />;
  }

  return <Outlet />; // ❗ REQUIRED
}
