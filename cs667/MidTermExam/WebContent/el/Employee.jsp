<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">

<HTML>
<HEAD>
<TITLE>MidTermExam_Lorber | Employee</TITLE>
</HEAD>
<BODY>
<H1>Customer Info Page</H1>
<DIV STYLE="width:300">
<TABLE>
<TR><TD>Employee ID:</TD><TD>${ currentEmployee.employeeId }</TD></TR>
<TR><TD>Full name:</TD><TD>${ currentEmployee.fullName }</TD></TR>
<TR><TD>Employee Type:</TD><TD>${ currentEmployee.employeeType }</TD></TR>
<TR><TD>Wage Rate:</TD><TD>${ currentEmployee.wageRate }</TD></TR>
</TABLE>
</DIV>
<A HREF="/jsp/EmployeeTimeCard.jsp">Time Card</A><br />
<A HREF="/jsp/EmployeeWagesSummary.jsp">Wages Summary</A><br />

</BODY>
</HTML>
