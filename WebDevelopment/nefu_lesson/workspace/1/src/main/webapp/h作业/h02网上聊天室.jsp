<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">

<html lang="zh">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>在线聊天室</title>
    <style>
        body {
            font-family: Arial, sans-serif;
        }
        #chatBox {
            border: 1px solid #ccc;
            height: 300px;
            overflow-y: scroll;
            margin-bottom: 10px;
        }
        table {
            width: 100%;
            border-collapse: collapse;
        }
        th, td {
            border: 1px solid #ccc;
            padding: 8px;
            text-align: left;
        }
    </style>
</head>
<body>

<h1>在线聊天室</h1>
<div id="chatBox"></div>
<input type="text" id="username" placeholder="用户名" required>
<input type="text" id="message" placeholder="消息内容" required>
<button onclick="sendMessage()">发送</button>

<table>
    <thead>
        <tr>
            <th>发言人</th>
            <th>发言内容</th>
            <th>发言时间</th>
        </tr>
    </thead>
    <tbody id="chatTableBody"></tbody>
</table>

<script>
    const chatTableBody = document.getElementById('chatTableBody');

    function loadMessages() {
        const messages = JSON.parse(localStorage.getItem('chatMessages')) || [];
        messages.forEach(msg => {
            addMessageToTable(msg.username, msg.message, msg.timestamp);
        });
    }

    function addMessageToTable(username, message, timestamp) {
        const row = chatTableBody.insertRow();
        row.insertCell(0).innerText = username;
        row.insertCell(1).innerText = message;
        row.insertCell(2).innerText = new Date(timestamp).toLocaleString();
    }

    function sendMessage() {
        const username = document.getElementById('username').value;
        const message = document.getElementById('message').value;
        const timestamp = Date.now();

        if (username && message) {
            const chatMessage = { username, message, timestamp };
            const messages = JSON.parse(localStorage.getItem('chatMessages')) || [];
            messages.push(chatMessage);
            localStorage.setItem('chatMessages', JSON.stringify(messages));

            addMessageToTable(username, message, timestamp);

            document.getElementById('message').value = ''; // 清空输入框
        } else {
            alert('请填写用户名和消息内容！');
        }
    }

    window.onload = loadMessages;
</script>

</body>
</html>
