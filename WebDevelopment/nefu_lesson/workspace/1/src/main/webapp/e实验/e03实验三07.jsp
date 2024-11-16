<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html lang="zh-CN">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>表单验证示例</title>
    <script>
        function validateForm() {
            const name = document.getElementById("name").value;
            const email = document.getElementById("email").value;
            const phone = document.getElementById("phone").value;
            const password = document.getElementById("password").value;
            const confirmPassword = document.getElementById("confirmPassword").value;
            const age = document.getElementById("age").value;
            const address = document.getElementById("address").value;

            // 清空错误信息
            const errorMessages = document.getElementById("errorMessages");
            errorMessages.innerHTML = "";

            // 检查是否为空
            if (!name || !email || !phone || !password || !confirmPassword || !age || !address) {
                errorMessages.innerHTML += "<p>所有字段都是必填的。</p>";
                return false;
            }

            // 正则表达式验证
            const emailPattern = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
            const phonePattern = /^\d{10}$/; // 10位数字

            if (!emailPattern.test(email)) {
                errorMessages.innerHTML += "<p>请输入有效的电子邮件地址。</p>";
                return false;
            }

            if (!phonePattern.test(phone)) {
                errorMessages.innerHTML += "<p>电话号码必须是11位数字。</p>";
                return false;
            }

            if (password.length < 6) {
                errorMessages.innerHTML += "<p>密码必须至少6个字符。</p>";
                return false;
            }

            if (password !== confirmPassword) {
                errorMessages.innerHTML += "<p>密码和确认密码不匹配。</p>";
                return false;
            }

            if (isNaN(age) || age <= 0) {
                errorMessages.innerHTML += "<p>年龄必须是一个正数。</p>";
                return false;
            }

            alert("表单验证通过！");
            return true; // 表单验证通过
        }
    </script>
</head>
<body>
    <h2>用户信息表单</h2>
    <div id="errorMessages" style="color: red;"></div>
    <form onsubmit="return validateForm()">
        <label for="name">姓名:</label>
        <input type="text" id="name" name="name"><br><br>

        <label for="email">电子邮件:</label>
        <input type="text" id="email" name="email"><br><br>

        <label for="phone">电话号码:</label>
        <input type="text" id="phone" name="phone"><br><br>

        <label for="password">密码:</label>
        <input type="password" id="password" name="password"><br><br>

        <label for="confirmPassword">确认密码:</label>
        <input type="password" id="confirmPassword" name="confirmPassword"><br><br>

        <label for="age">年龄:</label>
        <input type="number" id="age" name="age"><br><br>

        <label for="address">地址:</label>
        <input type="text" id="address" name="address"><br><br>

        <input type="submit" value="提交">
    </form>
</body>
</html>
