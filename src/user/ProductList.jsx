import { useEffect, useState } from "react";
import api from "../api/axios";

export default function ProductList() {
  const [products, setProducts] = useState([]);

  useEffect(() => {
    api.get("/products").then((res) => setProducts(res.data));
  }, []);

  return (
    <div className="container mt-4">
      <h3>Products</h3>
      <div className="row">
        {products.map((p) => (
          <div key={p._id} className="col-md-4">
            <div className="card mb-3">
              <div className="card-body">
                <h5>{p.name}</h5>
                <p>₹{p.price}</p>
                <button className="btn btn-primary">Add to Cart</button>
              </div>
            </div>
          </div>
        ))}
      </div>
    </div>
  );
}
