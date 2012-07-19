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
 * Servlet implementation class CustomerOrderServlet
 */
@WebServlet("/CustomerOrderServlet")
    public class CustomerOrderServlet extends HttpServlet {
		private static final long serialVersionUID = 1L;
		
		/**
     	 * @see HttpServlet#HttpServlet()
         */
        public CustomerOrderServlet() {
            super();
        }

   
        public void init() throws ServletException
        {
        	synchronized (this) {
        		ProductBeanCollection products = new ProductBeanCollection();
        		
        		products.append(new ProductBean("apple", 0.25));
        		products.append(new ProductBean("peach", 0.50));
        		products.append(new ProductBean("avocado", 1.50));
        	    getServletContext().setAttribute("products", products);
        	}
        }
    
	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		 HttpSession session = request.getSession();
         CustomerInfo info = (CustomerInfo) session.getAttribute("cust");
         if (null == info) {
        	 String register = new String("CustomerInfoServlet");
        	 response.setContentType("text/html");
        	 response.sendRedirect(register);
        	 return;
         }
 
         String operation = request.getParameter("operation");

         String page;         
         if (operation.contentEquals("balance")) {
        	 page = new String("/jsp/Balance.jsp");
         } else if (operation.contentEquals("order")) {
        	 page = new String("/jsp/Order.jsp");
         } else if (operation.contentEquals("payment")) {
    		 page = new String("/jsp/Payment.jsp");
         } else {
        	 page = new String("/jsp/CustomerInfo.jsp");
         }
        
         RequestDispatcher rd = request.getRequestDispatcher(page);
         rd.forward(request, response);
         return;
    }
            
	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
            doGet(request, response);
	}


    }
