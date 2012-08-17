package tgl.project.entity;

import java.util.Set;
import java.util.TreeSet;

import static javax.persistence.CascadeType.REMOVE;
import javax.persistence.Entity;
import javax.persistence.FetchType;
import javax.persistence.Id;
import javax.persistence.ManyToMany;
import javax.persistence.ManyToOne;
import javax.persistence.Table;

@Entity
@Table(name = "TGL_PROJECTS")
public class Project implements java.io.Serializable {
    private static final long serialVersionUID = 1L;
	
    private Set<Employee> employees;
    private Company company;
    private String projectCode;
    private String projectName;

    public Project() {
    }

    public Project(String code, String name) {
    	this.employees = new TreeSet<Employee>();
        this.projectCode = code;
        this.projectName = name;
    }

    @ManyToMany(cascade = REMOVE, mappedBy = "projects", fetch = FetchType.EAGER)
    public Set<Employee> getEmployees() {
        return this.employees;
    }

    public void setEmployees(Set<Employee> employees) {
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