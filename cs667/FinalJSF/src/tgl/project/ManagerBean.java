package tgl.project;

import tgl.project.request.Request;
import tgl.project.util.CompanyDetails;
import tgl.project.util.EmployeeDetails;
import tgl.project.util.ProjectDetails;
import tgl.project.entity.Company;
import tgl.project.entity.Employee;
import tgl.project.entity.Project;

import java.util.ArrayList;
import java.util.List;

import javax.ejb.EJB;
import javax.faces.bean.ManagedBean;
import javax.faces.bean.SessionScoped;
import javax.faces.context.FacesContext;
import javax.faces.model.SelectItem;
import javax.servlet.http.HttpServletRequest;

@ManagedBean 
@SessionScoped
public class ManagerBean {

	@EJB
	Request bean;
	
	private String companyId;
	private Company currentCompany;
	private String page;
	private String employeeId;
	private Employee currentEmployee;

	public String viewEmployee() {
		HttpServletRequest request = (HttpServletRequest)FacesContext.getCurrentInstance().getExternalContext().getRequest();
	    String id = request.getParameter("employeeId");
	    this.setEmployeeId(id);
		return("view-employee");
	}
	
	public String updateEmployee() {
    	bean.update(this.currentEmployee);
    	return("employees");
	
	}
	
	public String editEmployee() {
		HttpServletRequest request = (HttpServletRequest)FacesContext.getCurrentInstance().getExternalContext().getRequest();
	    String id = request.getParameter("employeeId");
	    this.setEmployeeId(id);
		return("edit-employee");	    
	}
	
	public List<SelectItem> getCompanies() {
		List<SelectItem> companies = new ArrayList<SelectItem>();
		companies.add(new SelectItem("--- Select Company ---"));
		
		List<CompanyDetails> companyDetails = bean.getAllCompanies();
		for (CompanyDetails detail : companyDetails) {
			companies.add(new SelectItem(detail.getId()));
		}
		return companies;
	}

	public String getCompanyId() {
		return this.companyId;
	}
	
	public void setCompanyId(String companyId) {
		this.companyId = companyId;
		this.currentCompany = bean.getCompanyBean(companyId);
	}

	public String getEmployeeId() {
		return this.employeeId;
	}
	
	public void setEmployeeId(String employeeId) {
		this.employeeId = employeeId;
		this.currentEmployee = bean.getEmployeeBean(employeeId);
	}

	public Company getCurrentCompany() {
		return this.currentCompany;
	}

	public Employee getCurrentEmployee() {
		return this.currentEmployee;
	}

	public String getPage() {
		return this.page;
	}
	
	public void openPage(String page) {
		this.page = page;
	}
	
	public List<ProjectDetails> getAllProjects() {
		List<ProjectDetails> projectDetails = bean.getAllProjects(this.currentCompany);
		return projectDetails; 
 	}

	public List<EmployeeDetails> getAllEmployees() {
		List<EmployeeDetails> employeeDetails = bean.getAllEmployees(this.currentCompany);
		return employeeDetails;
 	}
	
	public List<EmployeeDetails> getAllEmployees(Project project) {
		List<EmployeeDetails> employeeDetails = bean.getAllEmployees(project);
		return employeeDetails;
 	}
}
