package servlets;

import javax.faces.application.*;
import javax.faces.bean.*;
import javax.faces.context.*;

@ManagedBean
public class CustomerBean {
	private String customerID = "";
	private String firstName = "";
	private String lastName = "";
   	private String emailAddress = "";
    private boolean idTaken = false;

	public String getCustomerID() {
		return(customerID);
	}
	
	public void setCustomerID(String id) {
		customerID = ServletUtilities.filter(id);
	}

	public String getFirstName() {
		return(firstName);
	}
	
	public void setFirstName(String name) {
		firstName = ServletUtilities.filter(name);
	}

	public String getLastName() {
		return(lastName);
	}
	
	public void setLastName(String name) {
		lastName = ServletUtilities.filter(name);
	}

	public String getEmailAddress() {
		return(emailAddress);
	}
	
	public void setEmailAddress(String email) {
		emailAddress = ServletUtilities.filter(email);
	}

	public String doRegister() {
		FacesContext context = FacesContext.getCurrentInstance();
		if (isComplete()) {
			
		} else {
			
		}
		if (context.getMessageList().size() > 0) {
			return(null);
		} else {
			return("register");
		}
	}
	
        public boolean getIdTaken() {
                return(idTaken);
        }

        public void setIdTaken(boolean taken) {
                idTaken = taken;
        }

	public boolean isComplete() {
		boolean flag = hasValue(customerID) &&
				hasValue(firstName) &&
				hasValue(lastName) &&
				hasValue(emailAddress);
		return(flag);
	}	

	public boolean isPartial() {
		boolean flag = hasValue(customerID) ||
				hasValue(firstName) ||
				hasValue(lastName) ||
				hasValue(emailAddress);
		return(flag);
	}	

	public boolean hasValue(String str) {
	  return((str != null) && (!str.equals("")));
	}
}
