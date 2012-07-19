package servlets;

public class CustomerBean {
	private String customerID = "";
	private String firstName = "";
	private String lastName = "";
   	private String emailAddress = "";

   	public CustomerBean() {
   		
   	}
   	
    public CustomerBean(String id, String firstName, String lastName, String emailAddress) {
        this.customerID = id;
        this.firstName = firstName;
        this.lastName = lastName;
        this.emailAddress = emailAddress;
    }

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

}
