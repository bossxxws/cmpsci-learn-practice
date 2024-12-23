<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<%@ page import="java.awt.Color"%>
<%@ page import="java.awt.Font"%>
<%@ page import="java.awt.Graphics"%>
<%@ page import="java.awt.image.BufferedImage"%>
<%@ page import="javax.imageio.ImageIO"%>
<%@ page import="java.util.Random"%>
<%@ page import="javax.servlet.http.Cookie"%>
<%@ page import="javax.servlet.http.HttpServletRequest"%>
<%@ page import="javax.servlet.http.HttpServletResponse"%>

<%
    String action = request.getParameter("action");
    String captcha = null;

    // 处理验证码生成
    if ("generate".equals(action)) {
        Random random = new Random();
        StringBuilder captchaBuilder = new StringBuilder();
        for (int i = 0; i < 6; i++) { // 生成6位数字验证码
            captchaBuilder.append(random.nextInt(10)); // 生成0-9的数字
        }
        captcha = captchaBuilder.toString();

        // 将验证码保存到 Cookie 中
        Cookie captchaCookie = new Cookie("captcha", captcha);
        captchaCookie.setMaxAge(300); // 5分钟有效
        response.addCookie(captchaCookie);

        // 创建验证码图像
        int width = 150;
        int height = 50;
        BufferedImage bufferedImage = new BufferedImage(width, height, BufferedImage.TYPE_INT_RGB);
        Graphics g = bufferedImage.getGraphics();
        g.setColor(Color.WHITE);
        g.fillRect(0, 0, width, height);
        g.setColor(Color.BLACK);
        g.setFont(new Font("Arial", Font.BOLD, 30));
        g.drawString(captcha, 30, 35);
        g.dispose();

        // 输出图像
        response.setContentType("image/gif");
        ImageIO.write(bufferedImage, "gif", response.getOutputStream());
        return; // 结束当前请求
    }

    // 处理表单提交
    String userCaptcha = request.getParameter("captchaInput");
    String serverCaptcha = null;

    // 获取 Cookie 中的验证码
    Cookie[] cookies = request.getCookies();
    if (cookies != null) {
        for (Cookie cookie : cookies) {
            if ("captcha".equals(cookie.getName())) {
                serverCaptcha = cookie.getValue();
                break;
            }
        }
    }

    // 验证用户输入的验证码
    boolean isCaptchaValid = userCaptcha != null && userCaptcha.equals(serverCaptcha);
%>
<html>
<head>
    <meta charset="UTF-8">
    <title>验证码生成页面</title>
    <script>
        function refreshCaptcha() {
            document.getElementById("captchaImage").src = "<%= request.getRequestURI() %>?action=generate&" + Math.random();
        }
    </script>
</head>
<body>
    <h2>请输入验证码</h2>
    <form method="post" action="">
        验证码: <img id="captchaImage" src="<%= request.getRequestURI() %>?action=generate" alt="验证码" onclick="refreshCaptcha()" style="cursor:pointer;"><br>
        <input type="text" name="captchaInput" required><br><br>
        <input type="submit" value="提交">
    </form>

    <%
        if (userCaptcha != null) {
            if (isCaptchaValid) {
                out.println("<h3>验证码正确！</h3>");
            } else {
                out.println("<h3 style='color:red;'>验证码错误！请重新输入。</h3>");
            }
        }
    %>
</body>
</html>

