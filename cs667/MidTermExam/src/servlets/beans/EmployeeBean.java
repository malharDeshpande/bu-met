package servlets.beans;

import servlets.*;

public class EmployeeBean {
    private String employeeId = "":
    private int employeeType = 0;
    private String fullName = "";
    private double wageRage = 0.0;
    private List<TimeCardBean> timeCards;

    public String getEmployeeId() {
        return this.employeeId;
    }
    
    public void setEmployeeID(String id) {
        this.employeeID = ServletUtilities.filter(id);
    }
    
    public int getEmployeeType() {
        return this.employeeType;
    }

    public void setEmployeeType(int type) {
        this.employeeType = type;
    }

    public String getFullName() {
        return this.fullName;
    }
    
    public void setFullName(String name) {
        fullName = ServletUtilities.filter(name);
    }
    
    public double getWageRate() {
        return this.wageRate;
    }

    public void setWageRate(double rate) {
        this.wageRate = rate;
    }

    public List<TimeCardBean> getTimeCards() {
        return this.timeCards;
    }

    public void setTimeCards(List<TimeCardBean> cards) {
        this.timeCards = cards;
    }

    public TimeCardBean getTimeCard(int week) {
        return this.timeCards.at(week);
    }

    public TimeCardBean getCurrentTimeCard() {
        return this.timeCards.last();
    }
}
