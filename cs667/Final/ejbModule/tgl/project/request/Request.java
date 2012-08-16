package tgl.project.request;

import java.util.List;

import javax.ejb.Remote;

import tgl.project.entity.Project;
import tgl.project.entity.Company;
import tgl.project.util.CompanyDetails;
import tgl.project.util.EmployeeDetails;
import tgl.project.util.ProjectDetails;

@Remote
public interface Request {
    void test1();

    void test2();

    Company getCompanyBean(String id);
    
    Project getProjectBean(String code);

	List<CompanyDetails> getAllCompanies();
	
	List<ProjectDetails> getAllProjects(Company company);
	
	List<EmployeeDetails> getAllEmployees(Company company);
	
	void test3();
	
}