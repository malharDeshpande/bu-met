<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">

<HTML>
<HEAD>
<TITLE>MidTermExam_Lorber | Employee Page</TITLE>
</HEAD>
<BODY>
<H1>Customer Info Page</H1>
<DIV STYLE="width:300">
<jsp:useBean id="currentEmployee" type="servlets.beans.EmployeeBean" scope="session" />
<TABLE>
<TR><TD>Employee ID:</TD><TD><jsp:getProperty name="currentEmployee" property="employeeId" /></TD></TR>
<TR><TD>Full name:</TD><TD><jsp:getProperty name="currentEmployee" property="fullName" /></TD></TR>
<TR><TD>Employee Type:</TD><TD><jsp:getProperty name="currentEmployee" property="employeeType" /></TD></TR>
<TR><TD>Wage Rate:</TD><TD><jsp:getProperty name="currentEmployee" property="wageRate" /></TD></TR>
</TABLE>
</DIV>
<A HREF="/jsp/EmployeeTimeCard.jsp">Time Card</A><br />
<A HREF="/jsp/EmployeeWagesSummary.jsp">Wages Summary</A><br />

</BODY>
</HTML>