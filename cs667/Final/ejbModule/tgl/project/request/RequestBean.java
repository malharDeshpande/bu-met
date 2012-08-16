package tgl.project.request;

import javax.ejb.EJBException;
import javax.ejb.Stateful;
import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;

import tgl.project.entity.Company;
import tgl.project.entity.Employee;
import tgl.project.entity.Project;
import tgl.project.util.CompanyDetails;
import tgl.project.util.EmployeeDetails;
import tgl.project.util.ProjectDetails;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

@Stateful
public class RequestBean implements Request {

    @PersistenceContext(unitName="TGL_finalDB")
    private EntityManager em;

	@Override
	public void test1() {
		try {
			System.out.println("tgl.project.request.RequestBean.test1");

			Company company = em.find(Company.class, "NBM");
			if (company == null) {
				company = new Company("NBM", "National Business Machines");
			}
			
			System.out.println("Company " + company.getCompanyId() + ": " + company.getCompanyName());
			
			Employee emp1 = em.find(Employee.class, "001");
			if (emp1 == null) {
				emp1 = new Employee("001", "Karl Fardman");

				company.addEmployee(emp1);
				emp1.setCompany(company);
			}

	
			Employee emp2 = em.find(Employee.class, "002");
			if (emp2 == null) {
				emp2 = new Employee("002", "Newman");

				company.addEmployee(emp2);
				emp2.setCompany(company);
			}

			ArrayList<Project> projs = new ArrayList<Project>();
	
			Project proj1 = em.find(Project.class, "P-001");
			if (proj1 == null) {
				proj1 = new Project("P-001", "Integration");
			}

			Project proj2 = em.find(Project.class, "P-002");
			if (proj2 == null) {
				proj2 = new Project("P-002", "Training");
			}

			Project proj3 = em.find(Project.class, "P-003");
			if (proj3 == null) {
				proj3 = new Project("P-003", "ISO Compliance");
			}

			Project proj4 = em.find(Project.class, "P-004");
			if (proj4 == null) {
				proj4 = new Project("P-004", "Top Secret");
			}
			
			projs.add(proj1);
			projs.add(proj2);
			projs.add(proj3);
			projs.add(proj4);

			proj1.setCompany(company);
			proj2.setCompany(company);
			proj3.setCompany(company);
			proj4.setCompany(company);
			
			company.setProjects(projs);
			em.persist(company);
	        
	        for(Employee emp : company.getEmployees()) {
	        	System.out.println("Employee " + emp.getEmployeeId() + ": " + emp.getFullName());
	        }
	        
	        for (Project proj : company.getProjects()) {
	        	System.out.println("Project " + proj.getProjectCode() + " : " + proj.getProjectName());
	        }
        } catch (Exception ex) {
            throw new EJBException(ex);
        }

	}

	@Override
	public void test2() {
		try {
			System.out.println("tgl.project.request.RequestBean.test2");
			
			Company company = em.find(Company.class, "NBM");
			
			int e_count = 0;
			int p_count = 0;
			for(Employee emp : company.getEmployees()) {
				for(Project proj : company.getProjects()) {
					if (e_count == 0 && p_count < 3) {
						if (!proj.getEmployees().contains(emp)) {
							emp.addProject(proj);
							proj.addEmployee(emp);
						}
					}

					if (e_count == 1 && p_count > 0) {
						if (!proj.getEmployees().contains(emp)) {
							emp.addProject(proj);
							proj.addEmployee(emp);
						}
					}
					
					p_count++;
				}
				
				p_count = 0;
				e_count++;
			}
			
			em.persist(company);
			
			for(Project proj : company.getProjects()) {
				System.out.println("Project " + proj.getProjectCode() + " employees:");
				for(Employee emp : proj.getEmployees()) {
					System.out.println("Employee " + emp.getEmployeeId());
				}				
			}
			
		} catch (Exception ex) {
			throw new EJBException(ex);
		}
		
	}
	
	
	@Override
	public Project getProjectBean(String projectCode) {
		Project project = null;
		try {
			project = em.find(Project.class, projectCode);
		} catch (Exception ex) {
			throw new EJBException(ex);
		}
		return project;
	}

	@Override
	public Company getCompanyBean(String companyId) {
		Company company = null;
		try {
			company = em.find(Company.class, companyId);
		} catch (Exception ex) {
			throw new EJBException(ex);
		}
		return company;
	}

	
	@SuppressWarnings("unchecked")
	public List<CompanyDetails> getAllCompanies() {
		List<Company> companies = null;
		try {
			companies = (List<Company>) em.createNamedQuery("tgl.project.entity.Company.findAllCompanies").getResultList();
			return copyCompaniesToDetails(companies);
		} catch (Exception ex) {
			throw new EJBException(ex);
		}	
	}
	
	private List<CompanyDetails> copyCompaniesToDetails(List<Company> companies) {
		List<CompanyDetails> detailsList = new ArrayList<CompanyDetails>();
		Iterator<Company> iter = companies.iterator();
		
		while (iter.hasNext()) {
			Company company = (Company) iter.next();
			CompanyDetails companyDetails = new CompanyDetails(company.getCompanyId(), company.getCompanyName());
			detailsList.add(companyDetails);
		}
		return detailsList;
	}

	@Override
	@SuppressWarnings("unchecked")
	public List<ProjectDetails> getAllProjects(Company company) {
		List<Project> projects = null;
		try {
			projects = (List<Project>) em.createNamedQuery("tgl.project.entity.Company.findAllProjectsByCompany").setParameter("company", company).getResultList();
			return copyProjectsToDetails(projects);
		} catch (Exception ex) {
			throw new EJBException(ex);
		}	
	}
	
	
	@SuppressWarnings("unchecked")
	private List<ProjectDetails> copyProjectsToDetails(List<Project> projects) {
		List<ProjectDetails> detailsList = new ArrayList<ProjectDetails>();
		Iterator<Project> iter = projects.iterator();
		
		while (iter.hasNext()) {
			Project project = (Project) iter.next();
			
			List<Employee> employees = (List<Employee>) em.createNamedQuery("tgl.project.entity.Company.findAllEmployeesByProject").setParameter("projectCode", project.getProjectCode()).getResultList();
			List<EmployeeDetails> employeeDetails = copyEmployeesToDetails(employees);
			
			ProjectDetails projectDetails = new ProjectDetails(project.getProjectCode(), 
															   project.getProjectName(),
															   employeeDetails);
			detailsList.add(projectDetails);
		}
		return detailsList;
	}

	@Override
	@SuppressWarnings("unchecked")
	public List<EmployeeDetails> getAllEmployees(Company company) {
		List<Employee> employees = null;
		try {
			employees = (List<Employee>) em.createNamedQuery("tgl.project.entity.Company.findAllEmployeesByCompany").setParameter("company", company).getResultList();
			return copyEmployeesToDetails(employees);
		} catch (Exception ex) {
			throw new EJBException(ex);
		}	
	}

	private List<EmployeeDetails> copyEmployeesToDetails(List<Employee> employees) {
		List<EmployeeDetails> detailsList = new ArrayList<EmployeeDetails>();
		Iterator<Employee> iter = employees.iterator();
		
		while (iter.hasNext()) {
			Employee employee = (Employee) iter.next();
			EmployeeDetails employeeDetails = new EmployeeDetails(employee.getEmployeeId(), employee.getFullName());
			detailsList.add(employeeDetails);
		}
		return detailsList;
	}

	@Override
	@SuppressWarnings("unchecked")
	public List<EmployeeDetails> getAllEmployees(Project project) {
		List<Employee> employees = null;
		try {
			employees = (List<Employee>) em.createNamedQuery("tgl.project.entity.Company.findAllEmployeesByProject").setParameter("projectCode", project.getProjectCode()).getResultList();
			return copyEmployeesToDetails(employees);
		} catch (Exception ex) {
			throw new EJBException(ex);
		}	
	}

	@Override
	public Employee getEmployeeBean(String id) {
		Employee employee = null;
		try {
			employee = em.find(Employee.class, id);
		} catch (Exception ex) {
			throw new EJBException(ex);
		}
		return employee;
	}

	@Override
	public void update(Employee employee) {
		em.persist(employee);
	}


}
