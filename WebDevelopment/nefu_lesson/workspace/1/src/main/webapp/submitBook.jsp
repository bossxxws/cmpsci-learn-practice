<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="java.sql.*,com.nefu.jdbc.*" %>
<%
    String title = request.getParameter("title");
    String author = request.getParameter("author");
    String year = request.getParameter("year");
    String genre = request.getParameter("genre");
    String isbn = request.getParameter("isbn");

   
    	dbconn db=new dbconn();
        String sql = "INSERT INTO Books ("+title+", "+author+","+year+","+ genre+","+ isbn+")";

        db.executequery(sql);
        
        response.sendRedirect("inputBook.jsp"); // 提交成功后重定向回录入页面
    
%>
