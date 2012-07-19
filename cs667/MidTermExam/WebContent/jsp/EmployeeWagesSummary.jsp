<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">

<HTML>
<HEAD>
<TITLE>MidTermExam_Lorber | Wages Summary Page</TITLE>
</HEAD>
<BODY>
<H1>Wages Summary Page</H1>
<DIV STYLE="width:300">

<jsp:useBean id="currentEmployee" type="servlets.beans.EmployeeBean" scope="session" />
<H3>Employee</H3>
<TABLE>
<TR><TD>Employee ID:</TD><TD><jsp:getProperty name="currentEmployee" property="employeeId" /></TD></TR>
<TR><TD>Full name:</TD><TD><jsp:getProperty name="currentEmployee" property="fullName" /></TD></TR>
<TR><TD>Employee Type:</TD><TD><jsp:getProperty name="currentEmployee" property="employeeType" /></TD></TR>
<TR><TD>Wage Rate:</TD><TD><jsp:getProperty name="currentEmployee" property="wageRate" /></TD></TR>
</TABLE>

<H3>Wage Summary</H3>

<TABLE>
<TR>
<TD><STRONG>Week</STRONG></TD>
<TD><STRONG>HoursWorked</STRONG></TD>
<TD><STRONG>Wages</STRONG></TD>
</TR>

<% for(int index = 0; index < currentEmployee.getTimeCards().size(); ++index) { %>
<TR>
<TD><%= index+1 %></TD>
<TD><%= currentEmployee.getTimeCard(index).getWeekHours() %></TD>
<% if (1 == currentEmployee.getEmployeeId()) { %>
<TD>
<% if (currentEmployee.getTimeCard(index).getWeekHours() <= 40.0) { %>
<%= ((currentEmployee.getTimeCard(index).getWeekHours()/40.0)*currentEmployee.getWageRate()) %>
<% else %>
<%= currentEmployee.getWageRate() %>
<% end %>
</TD>
<% else if (2 == currentEmployee.getEmployeeId()) { %>
<TD>
<% if (currentEmployee.getTimeCard(index).getWeekHours() <= 40.0) { %>
<%= (currentEmployee.getTimeCard(index).getWeekHours() * currentEmployee.getWageRate()) %>
<% else %>
<% double overtime = currentEmployee.getTimeCard(index).getWeekHours - 40.0 %>
<%= ((40.0 * currentEmployee.getWageRate()) + (overtime * 1.5 * currentEmployee.getWageRate()) %>
<% end %>
</TD>
<% else %>
<TD>INVALID Employee Type, cannot determine wages.</TD>
<% end %>

</TR>
<% } %>

</TABLE>
</DIV>

</BODY>
</HTML>