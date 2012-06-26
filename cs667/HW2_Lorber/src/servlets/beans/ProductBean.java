package servlets.beans;

import servlets.*;

public class ProductBean {
	private String name = "";
	private double price = "";

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

}
