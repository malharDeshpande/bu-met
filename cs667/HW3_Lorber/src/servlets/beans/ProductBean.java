package servlets.beans;

import servlets.*;

public class ProductBean {
	private String name = "";
	private double price = 0.;

	public ProductBean(String name, double price) {
		this.name = name;
		this.price = price;
	}
	
	public String getName() {
		return(name);
	}
	
	public void setName(String n) {
		name = ServletUtilities.filter(n);
	}

	public double getPrice() {
		return(price);
	}
	
	public void setPrice(double value) {
		price = value;
	}

	public String formattedPrice() {
		StringBuffer fmted = new StringBuffer();
		fmted.append("$");
		fmted.append(price);
		return fmted.toString();
	}
}
