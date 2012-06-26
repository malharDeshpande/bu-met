<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">

<HTML>
<HEAD>
<TITLE></TITLE>
</HEAD>
<BODY>
<H1>Customer Info Page</H1>
<jsp:useBean id="cust" type="beans.CustomerInfo" scope="session" />

... Display Customer Info ...

<FORM action="CustomerOrderServlet">
     <%@ include file="/jsp/Actions.jsp" %>
<INPUT TYPE = "SUBMIT" VALUE="Submit">
</FORM>
</BODY>
</HTML>