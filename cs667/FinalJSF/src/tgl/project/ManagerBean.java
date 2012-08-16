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
import javax.faces.model.SelectItem;

@ManagedBean 
@SessionScoped
public class ManagerBean {

	@EJB
	Request bean;
	
	private String companyId;
	private Company currentCompany;
	
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

	public Company getCurrentCompany() {
		return this.currentCompany;
	}
	
	public List<ProjectDetails> getAllProjects() {
		List<ProjectDetails> projectDetails = bean.getAllProjects(this.currentCompany);
		return projectDetails; 
 	}

	public List<EmployeeDetails> getAllEmployees() {
		List<EmployeeDetails> employeeDetails = bean.getAllEmployees(this.currentCompany);
		return employeeDetails;
 	}

}
