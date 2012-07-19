package servlets;

import java.util.HashMap;

import javax.faces.application.*;
import javax.faces.bean.*;
import javax.faces.context.*;

@ManagedBean
public class SimpleController {
	private CustomerBean currentCustomer = new CustomerBean();

   	private static HashMap<String, CustomerBean> customers = new HashMap<String, CustomerBean>();

   	public CustomerBean getCurrentCustomer() {
   		return this.currentCustomer;
   	}
   	
   	public void setCurrentCustomer(CustomerBean cust) {
   		this.currentCustomer = cust;
   	}
   	
	public String doRegister() {
		FacesContext context = FacesContext.getCurrentInstance();
		if (!hasValue(this.currentCustomer.getCustomerID())) {
			context.addMessage(null, new FacesMessage("Customer ID required."));
		}
		if (!hasValue(this.currentCustomer.getFirstName())) {
			context.addMessage(null, new FacesMessage("First Name required."));
		}
		if (!hasValue(this.currentCustomer.getLastName())) {
			context.addMessage(null, new FacesMessage("Last Name required."));
		}
		if (!hasValue(this.currentCustomer.getEmailAddress())) {
			context.addMessage(null, new FacesMessage("E-Mail address required."));
		}
		
		if (context.getMessageList().size() > 0) {
			return("register");
		} else {
            synchronized (this) {
                if (customers.containsKey(this.currentCustomer.getCustomerID())) {
                    context.addMessage(null, new FacesMessage("Customer ID already taken."));
                    return("register");
                } else {
                    customers.put(this.currentCustomer.getCustomerID(), this.currentCustomer);
                    return("customer-info");
                }
            }
		}
	}
	

	public boolean hasValue(String str) {
	  return((str != null) && (!str.equals("")));
	}
}
