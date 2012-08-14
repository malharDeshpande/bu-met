package project.entity;

import java.util.ArrayList;
import java.util.Collection;
import static javax.persistence.CascadeType.ALL;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.OneToMany;
import javax.persistence.Table;

@Entity
@Table(name = "COMPANIES")
public class Company implements java.io.Serializable {
	private static final long serialVersionUID = 1L;
	
	private Collection<Employee> employees;
    private Collection<Project> projects;
    private String companyId;
    private String companyName;

    public Company() {
    }

    public Company(String id, String name) {
        this.employees = new ArrayList<Employee>();
        this.projects = new ArrayList<Project>();
        this.companyId = id;
        this.companyName = name;
    }

    @OneToMany(cascade = ALL, mappedBy = "company")
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

    @OneToMany(cascade = ALL, mappedBy = "company")
    public Collection<Project> getProjects() {
        return this.projects;
    }

    public void setProjects(Collection<Project> projects) {
        this.projects = projects;
    }

    public void addProject(Project project) {
        this.getProjects().add(project);
    }

    public void dropProject(Project project) {
        this.getProjects().remove(project);
    }

    @Id
    public String getCompanyId() {
        return this.companyId;
    }

    public void setCompanyId(String id) {
        this.companyId = id;
    }

    public String getCompanyName() {
        return this.companyName;
    }

    public void setCompanyName(String name) {
        this.companyName = name;
    }

}