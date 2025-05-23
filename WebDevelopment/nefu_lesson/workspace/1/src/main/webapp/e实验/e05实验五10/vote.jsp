<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <title>投票页面</title>
</head>
<body>

<%
    // 定义投票题目及选项
    String[] questions = {
        "你最喜欢的编程语言是什么？",
        "你最喜欢的开发环境是什么？"
    };

    String[][] options = {
        {"Java", "Python", "JavaScript", "C++", "Ruby"},
        {"Eclipse", "IntelliJ IDEA", "Visual Studio Code", "NetBeans", "Sublime Text"}
    };

    // 初始化票数数组（在会话中存储）
    int[][] votes = (int[][]) session.getAttribute("votes");
    if (votes == null) {
        votes = new int[questions.length][];
        for (int i = 0; i < questions.length; i++) {
            votes[i] = new int[options[i].length];
        }
        session.setAttribute("votes", votes);
    }

    // 检查是否有投票提交
    if (request.getMethod().equalsIgnoreCase("POST")) {
        for (int i = 0; i < questions.length; i++) {
            String choice = request.getParameter("choice" + i);
            if (choice != null) {
                int index = Integer.parseInt(choice);
                if (index >= 0 && index < options[i].length) {
                    votes[i][index]++; // 增加对应选项的票数
                }
            }
        }
        // 更新会话中的票数
        session.setAttribute("votes", votes);
    }

    // 显示投票表单
    if (request.getParameter("submit") == null) {
%>
    <h1>投票页面</h1>
    <form action="vote.jsp" method="post">
        <% for (int i = 0; i < questions.length; i++) { %>
            <h3><%= questions[i] %></h3>
            <% for (int j = 0; j < options[i].length; j++) { %>
                <input type="radio" name="choice<%= i %>" value="<%= j %>"> <%= options[i][j] %><br>
            <% } %>
        <% } %>
        <input type="submit" name="submit" value="提交投票">
    </form>
<%
    } else {
%>
    <h1>投票结果</h1>
    <% for (int i = 0; i < questions.length; i++) { %>
        <h3><%= questions[i] %></h3>
        <ul>
            <% for (int j = 0; j < options[i].length; j++) { %>
                <li><%= options[i][j] %>: <%= votes[i][j] %> 票</li>
            <% } %>
        </ul>
    <% } %>
    <a href="vote.jsp">返回投票</a>
<%
    }
%>

</body>
</html>
