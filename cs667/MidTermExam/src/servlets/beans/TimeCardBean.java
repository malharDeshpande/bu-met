package servlets.beans;

import servlets.*;

public class TimeCardBean {
    private double dayOne = 0.0;
    private double dayTwo = 0.0;
    private double dayThree = 0.0;
    private double dayFour = 0.0;
    private double dayFive = 0.0;
    private double daySix = 0.0;
    private double daySeven = 0.0;
    
    public double getDayOne() {
        return this.dayOne;
    }
    
    public void setDayOne(double hours) {
        this.dayOne = hours;
    }

    public double getDayTwo() {
        return this.dayTwo;
    }
    
    public void setDayTwo(double hours) {
        this.dayTwo = hours;
    }

    public double getDayThree() {
        return this.dayThree;
    }
    
    public void setDayThree(double hours) {
        this.dayThree = hours;
    }

    public double getDayFour() {
        return this.dayFour;
    }
    
    public void setDayFour(double hours) {
        this.dayFour = hours;
    }

    public double getDayFive() {
        return this.dayFive;
    }
    
    public void setDayFive(double hours) {
        this.dayFive = hours;
    }

    public double getDaySix() {
        return this.daySix;
    }
    
    public void setDaySix(double hours) {
        this.daySix = hours;
    }

    public double getDaySeven() {
        return this.daySeven;
    }
    
    public void setDaySeven(double hours) {
        this.daySeven = hours;
    }

    public double getWeekHours() {
        return (this.dayOne + this.dayTwo + this.dayThree + this.dayFour + this.dayFive + this.daySix + this.daySeven);
    }

}
