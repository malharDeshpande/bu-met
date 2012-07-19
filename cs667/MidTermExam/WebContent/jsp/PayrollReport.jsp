<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">

<HTML>
<HEAD>
<TITLE>MidTermExam_Lorber | Payroll Report Page</TITLE>
</HEAD>
<BODY>
<H1>Payroll Report Page</H1>

<jsp:useBean id="employees" type="java.util.HashMap<String, EmployeeBean>" scope="application" />
<% for (String key : employees.keySet()) { %>
<% EmployeeBean currentEmployee = employees.get(Key) %>
<jsp:include page="EmployeeWageSummary.jsp" />
<% } %>

</BODY>
</HTML>
