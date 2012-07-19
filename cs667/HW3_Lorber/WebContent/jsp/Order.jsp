<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">

<HTML>
<HEAD>
<TITLE>HW2_Lorber | Order</TITLE>
</HEAD>
<BODY>
<jsp:useBean id="products" type="servlets.beans.ProductBeanCollection" scope="application" />
<TABLE>
<TR>
  <TD></TD>
  <TD>Name</TD>
  <TD>Price</TD>
</TR>
<% for (int index = 0; index < products.getProducts().size(); ++index) { %>
<TR>
  <TD><%= (index + 1) %>.&nbsp;</TD>
  <TD><%= products.getProducts().elementAt(index).getName() %></TD>
  <TD><%= products.getProducts().elementAt(index).formattedPrice() %></TD>
</TR>
<% } %>
</TABLE>
<FORM action="CustomerOrderServlet">
     <%@ include file="/jsp/Actions.jsp" %>
<INPUT TYPE = "SUBMIT" VALUE="Submit">
</FORM>
</BODY>
</HTML>
