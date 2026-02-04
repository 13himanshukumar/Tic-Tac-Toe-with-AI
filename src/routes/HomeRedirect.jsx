import { Navigate } from "react-router-dom";

export default function HomeRedirect() {
  const role = localStorage.getItem("role");

  if (role === "ADMIN") return <Navigate to="/admin" replace />;
  if (role === "USER") return <Navigate to="/products" replace />;

  return <Navigate to="/" replace />;
}
