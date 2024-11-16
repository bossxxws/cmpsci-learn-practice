<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">

<html>
<head>
    <meta charset="UTF-8">
    <title>注册页面</title>
    <script>
        function validateForm() {
            var username = document.forms["registerForm"]["username"].value;
            var password = document.forms["registerForm"]["password"].value;
            var usernamePattern = /^[a-zA-Z]+$/; // 只含有字母
            var passwordPattern = /^[a-zA-Z0-9]{6,20}$/; // 长度在6到20之间，只可为字母和数字

            if (!usernamePattern.test(username)) {
                alert("用户名必须只包含字母！");
                return false;
            }
            if (!passwordPattern.test(password)) {
                alert("密码必须在6到20个字符之间，并且只能包含字母和数字！");
                return false;
            }
            return true; // 验证通过
        }
    </script>
</head>
<body>
    <h2>注册</h2>
    <form name="registerForm" onsubmit="return validateForm()" method="post">
        用户名: <input type="text" name="username" required><br><br>
        密码: <input type="password" name="password" required><br><br>
        <input type="submit" value="注册">
    </form>
</body>
</html>
