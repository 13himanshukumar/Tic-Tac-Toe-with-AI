import { useEffect, useState } from "react";
import "bootstrap/dist/css/bootstrap.min.css";

export default function ProductHome() {
  const [products, setProducts] = useState([]);

  // Temporary static data (backend later)
  useEffect(() => {
    setProducts([
      { id: 1, name: "Product A", price: 100 },
      { id: 2, name: "Product B", price: 250 },
      { id: 3, name: "Product C", price: 400 },
    ]);
  }, []);

  return (
    <div className="container mt-4">
      <h2 className="text-center mb-4">Product Home</h2>

      <div className="row">
        {products.map((product) => (
          <div key={product.id} className="col-md-4">
            <div className="card mb-3 shadow-sm">
              <div className="card-body">
                <h5 className="card-title">{product.name}</h5>
                <p className="card-text">₹ {product.price}</p>
                <button className="btn btn-primary w-100">Add to Cart</button>
              </div>
            </div>
          </div>
        ))}
      </div>
    </div>
  );
}
