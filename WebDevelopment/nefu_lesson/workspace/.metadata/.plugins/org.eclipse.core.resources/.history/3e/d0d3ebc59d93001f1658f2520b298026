<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<%
    String username = request.getParameter("yhm");
    String password = request.getParameter("pas1");
    String confirmPassword = request.getParameter("pas2");

    if (username.startsWith("user")) {
        out.println("<script>alert('该用户名已被注册');</script>");
        out.println("用户名: " + username + "<br>");
        out.println("密码: " + password + "<br>");
        out.println("确认密码: " + confirmPassword + "<br>");
    } else if (username.equals("admin")) {
        out.println("<script>alert('欢迎您，管理员');</script>");
    } else {
        out.println("<script>alert('注册成功');</script>");
    }
%>
