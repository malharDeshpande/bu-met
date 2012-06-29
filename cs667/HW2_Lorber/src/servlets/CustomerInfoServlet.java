package servlets;

import servlets.beans.*;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.Iterator;
import java.util.Map;
import java.util.HashMap;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

/**
 * Servlet implementation class CustomerInfoServlet
 */
@WebServlet("/CustomerInfoServlet")
    public class CustomerInfoServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;

        private static HashMap<String, CustomerInfo> customers = new HashMap<String, CustomerInfo>();
        /**
         * @see HttpServlet#HttpServlet()
         */
        public CustomerInfoServlet() {
        	super();
        }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
            CustomerInfo info = new CustomerInfo();
            populateBean(info, request);
		
            if (info.isComplete()) {
                submitInfo(info);
                if (info.getIdTaken()) {
                    showForm(request, response, info);
                } else {
                    
                    HttpSession session = request.getSession();
                    session.setAttribute("cust", info);

                    String page = "/jsp/CustomerInfo.jsp";
                    RequestDispatcher rd = request.getRequestDispatcher(page);
                    rd.forward(request, response);
                    return;
                }
            } else {
                showForm(request, response, info);
            }
        }
            
	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
            doGet(request, response);
	}

	private synchronized void submitInfo(CustomerInfo info) {
            if (CustomerInfoServlet.customers.containsKey(info.getCustomerID())) {
                info.setIdTaken(true);
            } else  {
                CustomerInfoServlet.customers.put(info.getCustomerID(), info);
            }
	}
	
	private void showForm(HttpServletRequest request,
                              HttpServletResponse response,
                              CustomerInfo info)
            throws ServletException, IOException {
            boolean isPartial = info.isPartial();
            response.setContentType("text/html");
            PrintWriter out = response.getWriter();
            String title = "Customer Info Servlet";
            out.println(ServletUtilities.headWithTitle(title) +
                        "<BODY BGCOLOR=\"\"><CENTER>\n" +
                        "<H1>" + title + "</H1>\n" +
                        warning(isPartial) +
                        "<DIV STYLE=\"width: 300\">\n" +
                        "<FORM>\n" + 
                        "<FIELDSET>\n" +
                        "<LEGEND>Customer Information</LEGEND>\n" +
                        "<TABLE>\n");
                        if (info.getIdTaken()) {
                            out.println(ServletUtilities.inputElementValueTaken("Customer ID", "customerID", info.getCustomerID()));
                        } else {
                            out.println(ServletUtilities.inputElement("Customer ID", "customerID", info.getCustomerID(), true, isPartial));
                        }
                        out.println(ServletUtilities.inputElement("First name", "firstName", info.getFirstName(), true, isPartial) +
                        ServletUtilities.inputElement("Last name", "lastName", info.getLastName(), true, isPartial) +
                        ServletUtilities.inputElement("E-mail address", "emailAddress", info.getEmailAddress(), true, isPartial) +
                        "<TR><TD></TD><TD><INPUT TYPE=\"SUBMIT\" VALUE=\"Register\"></TD></TR>\n" +
                        "</TABLE>\n" +
                        "</FIELDSET>\n" +
                        "</FORM>\n" +
                        "</DIV>\n" +
                        "</BODY></HTML>");
	}

	private String warning(boolean isPartial) {
            if (isPartial) {
                return("<H2>Complete required fields and re-submit.</H2>\n");
            } else {
                return("");
            }
	}
	
	private void populateBean(CustomerInfo info, HttpServletRequest request) {
            String value = request.getParameter("customerID");
            if ((value != null) && (!value.equals(""))) {
                info.setCustomerID(value);
            }

            value = request.getParameter("firstName");
            if ((value != null) && (!value.equals(""))) {
                info.setFirstName(value);
            }

            value = request.getParameter("lastName");
            if ((value != null) && (!value.equals(""))) {
                info.setLastName(value);
            }

            value = request.getParameter("emailAddress");
            if ((value != null) && (!value.equals(""))) {
                info.setEmailAddress(value);
            }


	}

    }
