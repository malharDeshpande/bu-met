package servlets.beans;

import java.util.Vector;

public class ProductBeanCollection {
	private Vector<ProductBean> products = new Vector<ProductBean>();
		
	public Vector<ProductBean> getProducts() {
		return(products);
	}
	
	public void setProducts(Vector<ProductBean> products) {
		this.products = products;
	}

	public void append(ProductBean product)  {
		this.products.addElement(product);
	}
}
