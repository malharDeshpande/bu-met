package project.request;

import javax.ejb.EJBException;
import javax.ejb.Stateful;
import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;

import project.entity.Company;
import project.entity.Employee;
import project.entity.Project;

import java.util.ArrayList;
import java.util.Collection;
import java.util.logging.Logger;

@Stateful
public class RequestBean implements Request {

    private static final Logger logger = Logger.getLogger(
            "project.request.RequestBean");

    @PersistenceContext(unitName="finalDB")
    private EntityManager em;

	@Override
	public void test1() {
		try {
			System.out.println("project.request.RequestBean.test1");

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
			System.out.println("project.request.RequestBean.test2");
			
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

}
