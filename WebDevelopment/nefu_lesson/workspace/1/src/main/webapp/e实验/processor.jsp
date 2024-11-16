<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<%
    String username = request.getParameter("yhm");

    if (username.equals("admin")) {
        // Forward to admin page
        request.setAttribute("message", "欢迎您，管理员");
        request.getRequestDispatcher("admin.jsp").forward(request, response);
    } else {
        // Forward to user page
        request.setAttribute("message",  username+", 您好");
        request.getRequestDispatcher("user.jsp").forward(request, response);
    }
%>
