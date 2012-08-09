package project.entity;

import java.util.Collection;
import static javax.persistence.CascadeType.REMOVE;
import javax.persistence.Entity;
import javax.persistence.FetchType;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToMany;
import javax.persistence.ManyToOne;
import javax.persistence.Table;
import javax.persistence.JoinTable;

@Entity
@Table(name = "EMPLOYEES")
public class Employee implements java.io.Serializable {
	private static final long serialVersionUID = 1L;
	
	private Collection<Project> projects;
    private Company company;
    private String employeeId;
    private String fullName;

    public Employee() {
    }

    public Employee(String id, String name) {
        this.employeeId = id;
        this.fullName = name;
    }

    @ManyToMany(cascade = REMOVE, fetch = FetchType.EAGER)
    @JoinTable(name = "EMPLOYEES_PROJECTS", 
      joinColumns = @JoinColumn(name = "employee_id", referencedColumnName = "employeeId"), 
      inverseJoinColumns = @JoinColumn(name = "project_id", referencedColumnName = "projectCode"))
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

    @ManyToOne
    public Company getCompany() {
        return this.company;
    }

    public void setCompany(Company company) {
        this.company = company;
    }

    @Id
    public String getEmployeeId() {
        return this.employeeId;
    }

    public void setEmployeeId(String id) {
        this.employeeId = id;
    }

    public String getFullName() {
        return this.fullName;
    }

    public void setFullName(String name) {
        this.fullName = name;
    }

}