<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>

<!-- chapter2 -->
<%

String user=request.getParameter("id");
String gender=request.getParameter("gender");
String hobby=request.getParameter("hobby");
String f1=request.getParameter("f1");

%>

<%=user%><br>
<%=gender%><br>
<%= hobby %>
<%=f1 %>
</body>
</html>