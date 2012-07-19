<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">

<HTML>
<HEAD>
<TITLE>MidTermExam_Lorber | Wages Summary Page</TITLE>
</HEAD>
<BODY>
<H1>Wages Summary Page</H1>

<jsp:useBean id="currentEmployee" type="servlets.beans.EmployeeBean" scope="session" />
<H3>Employee</H3>
<TABLE>
<TR><TD>Employee ID:</TD><TD><c:out value="${currentEmployee.getEmployeeId()}" /></TD></TR>
<TR><TD>Full name:</TD><TD><c:out value="${currentEmployee.getFullName()}" /></TD></TR>
<TR><TD>Employee Type:</TD><TD><c:out value="${currentEmployee.getEmployeeType()}" /></TD></TR>
<TR><TD>Wage Rate:</TD><TD></TD><c:out value="${currentEmployee.getWageRate()}" /></TR>
</TABLE>

<H3>Wage Summary</H3>

<TABLE>
<TR>
<TD><STRONG>Week</STRONG></TD>
<TD><STRONG>HoursWorked</STRONG></TD>
<TD><STRONG>Wages</STRONG></TD>
</TR>

<% int index = 1 %>
<c:forEach var="timeCard" items="${currentEmployee.getTimeCards()}">
<TR>
<TD><c:out value="${index}" /></TD>
<TD><c:out value="${timeCard.getWeekHours()}" /></TD>
<TD>
<c:if test="${currentEmployee.getEmployeeId() == 1}">
<c:if test="${timeCard.getWeekHours >= 40.0}">
<c:out value="${currentEmployee.getWageRate()}" />
</c:if>

<c:if test="${timeCard.getWeekHours < 40.0}">
<c:out value="${(timeCard.getWeekHours()/40.)*currentEmployee.getWageRate()}" />
</c:if>
</c:if>


<c:if test="${currentEmployee.getEmployeeId() == 2}">

<c:if test="${timeCard.getWeekHours >= 40.0}">
<c:set var="overtime" value="${timeCard.getWeekHours - 40.0}" />
<c:out value="${(40.0 * currentEmployee.getWageRate()) + (overtime * 1.5 * currentEmployee.getWageRate())}" />
</c:if>

<c:if test="${timeCard.getWeekHours < 40.0}">
<c:out value="${timeCard.getWeekHours()*currentEmployee.getWageRate()}" />
</c:if>

</c:if>

</TD>

</TR>
</c:forEach>

</TABLE>


</BODY>
</HTML>
