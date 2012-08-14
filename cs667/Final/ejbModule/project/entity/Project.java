package project.entity;

import java.util.ArrayList;
import java.util.Collection;
import static javax.persistence.CascadeType.REMOVE;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.ManyToMany;
import javax.persistence.ManyToOne;
import javax.persistence.Table;

@Entity
@Table(name = "PROJECTS")
public class Project implements java.io.Serializable {
    private static final long serialVersionUID = 1L;
	
    private Collection<Employee> employees;
    private Company company;
    private String projectCode;
    private String projectName;

    public Project() {
    }

    public Project(String code, String name) {
    	this.employees = new ArrayList<Employee>();
        this.projectCode = code;
        this.projectName = name;
    }

    @ManyToMany(cascade = REMOVE, mappedBy = "projects")
    public Collection<Employee> getEmployees() {
        return this.employees;
    }

    public void setEmployees(Collection<Employee> employees) {
        this.employees = employees;
    }

    public void addEmployee(Employee employee) {
        this.getEmployees().add(employee);
    }

    public void dropEmployee(Employee employee) {
        this.getEmployees().remove(employee);
    }

    @ManyToOne
    public Company getCompany() {
        return this.company;
    }

    public void setCompany(Company company) {
        this.company = company;
    }

    @Id
    public String getProjectCode() {
        return this.projectCode;
    }

    public void setProjectCode(String code) {
        this.projectCode = code;
    }

    public String getProjectName() {
        return this.projectName;
    }

    public void setProjectName(String name) {
        this.projectName = name;
    }

}