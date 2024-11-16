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
String sql="select * from user where id="+request.getParameter("id");
out.print(sql);
dbconn db=new dbconn();
ResultSet rs=null;
rs=db.executequery(sql);
rs.next();

%>
<form action="modifysave.jsp">
您的学号为：<input type="text" name="id" value=<%=rs.getString(1) %> readonly><br>
您的姓名为：<input type="text" name="xm" value=<%=rs.getString(2) %> readonly><br>
您的语文成绩为：<input type="text" name="yw" value=<%=rs.getString(3) %>><br>
您的数学成绩为：<input type="text" name="sx" value=<%=rs.getString(4) %>><br>
您的英语成绩为：<input type="text" name="yy" value=<%=rs.getString(5) %>><br>
<input type="submit" value="修改">
</form>
</body>
</html>