<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">

<HTML>
<HEAD>
<TITLE>HW2_Lorber | Customer Info Page</TITLE>
</HEAD>
<BODY>
<H1>Customer Info Page</H1>
<DIV STYLE="width:300">
<jsp:useBean id="cust" type="servlets.beans.CustomerInfo" scope="session" />
<TABLE>
<TR><TD>Customer ID:</TD><TD><jsp:getProperty name="cust" property="customerID" /></TD></TR>
<TR><TD>First name:</TD><TD><jsp:getProperty name="cust" property="firstName" /></TD></TR>
<TR><TD>Last name:</TD><TD><jsp:getProperty name="cust" property="lastName" /></TD></TR>
<TR><TD>E-mail address:</TD><TD><jsp:getProperty name="cust" property="emailAddress" /></TD></TR>
</TABLE>
</DIV>
<FORM action="CustomerOrderServlet">
     <%@ include file="/jsp/Actions.jsp" %>
<INPUT TYPE = "SUBMIT" VALUE="Submit">
</FORM>
</BODY>
</HTML>