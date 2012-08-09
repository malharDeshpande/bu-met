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
			Company company = new Company("NBM", "National Business Machines");
			
			Employee emp1 = new Employee("001", "Karl Fardman");
			company.addEmployee(emp1);
	
			Employee emp2 = new Employee("002", "Newman");
			company.addEmployee(emp2);
	
			ArrayList<Project> projs = new ArrayList<Project>();
	
			Project proj1 = new Project("P-001", "Integration");
			projs.add(proj1);
	
			Project proj2 = new Project("P-002", "Training");
			projs.add(proj2);
	
			Project proj3 = new Project("P-003", "ISO Compliance");
			projs.add(proj3);
	
			Project proj4 = new Project("P-004", "Top Secret");
			projs.add(proj4);
			
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
			Company company = em.find(Company.class, "NBM");
			
			int e_count = 0;
			int p_count = 0;
			for(Employee emp : company.getEmployees()) {
				for(Project proj : company.getProjects()) {
					if (e_count == 0 && p_count < 4) {
						emp.addProject(proj);
					}

					if (e_count == 1 && p_count > 0) {
						emp.addProject(proj);
					}
					
					p_count++;
				}
				
				e_count++;
			}
			
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
