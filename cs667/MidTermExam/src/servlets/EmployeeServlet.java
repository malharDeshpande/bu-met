package servlets;

import servlets.beans.*;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.Iterator;
import java.util.Map;
import java.util.HashMap;
import java.util.Vector;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

/**
 * Servlet implementation class EmployeeServlet
 */
@WebServlet("/EmployeeServlet")
    public class EmployeeServlet extends HttpServlet {
        private static final long serialVersionUID = 1L;

        /**
     	 * @see HttpServlet#HttpServlet()
         */
        public EmployeeServlet() {
            super();
        }
        
        
        public void init() throws ServletException
        {
            synchronized (this) {
                HashMap<String, EmployeeBean> employees = new HashMap<String, EmployeeBean>();
                getServletContext().setAttribute("employees", employees);
            }
        }
        
	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
            String action = request.getParameter("action");

            String page;         
            if (action.contentEquals("newEmployee")) {
                page = new String("NewEmployee.html");
            } else if (operation.contentEquals("existingEmployee")) {
                page = new String("ExistingEmployee.html");
            }
                        
            response.setContentType("text/html");
            response.sendRedirect(page);
            return;
        }

            
	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
            EmployeeBean employee = new EmployeeBean;
            this.populateBean(employee, request);
            
            HashMap<String, EmployeeBean> employees = getServletContext().getAttribute("employees");

            synchronized (this) {
                if (employee.getFullName().equals("")) {
                    // no name, must be an existing employee
                    if (employees.containsKey(employees.getEmployeeId())) {
                        employee = employees.get(employee.getEmployeeId());
                        
                        HttpSession session = request.getSession();
                        session.setAttribute("currentEmployee", employee);
                        
                        String page = "/jsp/Employee.jsp";
                        RequestDispatcher rd = request.getRequestDispatcher(page);
                        rd.forward(request, response);
                        return;

                    } else {
                        // not found
                        response.setContentType("text/html");
                        response.sendRedirect("ErrorPage.html");
                        return;
                    }
                    
                } else {
                    // a new employee!
                   
                    String page;
                    if (employees.containsKey(employees.getEmployeeId())) {
                        // already exists
                        page = new String("ErrorPage.html");
                    } else {
                        // store and return to Welcome page
                        employees.put(employee.getEmployeeId(), employee);
                        page = new String("Welcome.html");
                    }
                    
                    response.setContentType("text/html");
                    response.sendRedirect(page);
                    return;
                }
            }
	}

 	private void populateBean(EmployeeBean employee, HttpServletRequest request) {
            String value = request.getParameter("employeeID");
            if ((value != null) && (!value.equals(""))) {
                employee.setEmployeeID(value);
            }

            value = request.getParameter("fullName");
            if ((value != null) && (!value.equals(""))) {
                employee.setFullName(value);
            }

            value = request.getParameter("employeeType");
            if ((value != null) && (!value.equals(""))) {
                employee.setEmployeeType(Integer.parseInt(value));
            }

            value = request.getParameter("wageRate");
            if ((value != null) && (!value.equals(""))) {
                employee.setWageRate(Double.parseDouble(value));
            }


	}


    }
