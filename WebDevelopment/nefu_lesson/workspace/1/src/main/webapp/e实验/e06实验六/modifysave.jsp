<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    <%@ page import="java.sql.*,com.nefu.jdbc.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<%
String id=request.getParameter("id");
String xm=request.getParameter("xm");
String yw=request.getParameter("yw");
String sx=request.getParameter("sx");
String yy=request.getParameter("yy");
String sql="update  user set yw='"+yw+"',sx='"+sx+"',yy='"+yy+"'where id='"+id+"'";
dbconn db=new dbconn();
int i=db.executeupdate(sql);


%>
成功修改<%=i %>条记录
</body>
</html>