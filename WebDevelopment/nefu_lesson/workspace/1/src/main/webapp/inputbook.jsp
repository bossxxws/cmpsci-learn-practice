<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="java.sql.*,com.nefu.jdbc.*" %>
<!DOCTYPE html>
<html lang="zh">
<head>
    <meta charset="UTF-8">
    <title>书目信息录入</title>
    <style>
        body { font-family: Arial, sans-serif; margin: 20px; }
        input, select { margin: 5px 0; padding: 10px; width: 300px; }
        button { padding: 10px 15px; }
    </style>
</head>
<body>
    <h1>录入书目信息</h1>
    <form action="submitBook.jsp" method="POST">
        <label for="title">书名:</label><br>
        <input type="text" id="title" name="title" required><br>
        <label for="author">作者:</label><br>
        <input type="text" id="author" name="author" required><br>
        <label for="year">出版年份:</label><br>
        <input type="number" id="year" name="year"><br>
        <label for="genre">类型:</label><br>
        <input type="text" id="genre" name="genre"><br>
        <label for="isbn">ISBN:</label><br>
        <input type="text" id="isbn" name="isbn"><br>
        <button type="submit">提交</button>
    </form>

    <h2>已录入书籍</h2>
    <div id="book-list">
        <%
            Connection conn = null;
            Statement stmt = null;
            ResultSet rs = null;
            try {
            	dbconn db=new dbconn();
                rs = db.executequery("SELECT * FROM user");

                while (rs.next()) {
                    out.println("书名: " + rs.getString("title") + "<br>");
                    out.println("作者: " + rs.getString("author") + "<br>");
                    out.println("出版年份: " + rs.getInt("publication_year") + "<br>");
                    out.println("类型: " + rs.getString("genre") + "<br>");
                    out.println("ISBN: " + rs.getString("isbn") + "<br><br>");
                }
            } catch (SQLException e) {
                e.printStackTrace();
            } finally {
                if (rs != null) try { rs.close(); } catch (SQLException e) {}
            }
        %>
    </div>
</body>
</html>
