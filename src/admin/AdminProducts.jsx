import { useEffect, useState } from "react";
import api from "../api/axios";

export default function AdminProducts() {
  const [products, setProducts] = useState([]);

  useEffect(() => {
    api.get("/products").then((res) => setProducts(res.data));
  }, []);

  return (
    <div className="container mt-4">
      <h3>Admin Product Management</h3>
      {products.map((p) => (
        <div key={p._id} className="border p-2 mb-2">
          {p.name} - ₹{p.price}
        </div>
      ))}
    </div>
  );
}
