<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<%@ page import="com.nefu.bean.LarvaePrediction" %>
<html>
<head>
    <meta charset="UTF-8">
    <title>落叶松毛虫发生量预测</title>
</head>
<body>
    <h1>落叶松毛虫发生量预测</h1>
    <form action="" method="post">
        <label for="precipitation">8月降水量 (mm):</label>
        <input type="text" id="precipitation" name="precipitation" required><br>
        
        <label for="humidity">8月相对湿度 (%):</label>
        <input type="text" id="humidity" name="humidity" required><br>
        
        <label for="maxTempJan">1月极高温度 (°C):</label>
        <input type="text" id="maxTempJan" name="maxTempJan" required><br>
        
        <label for="minTempJan">1月极低温度 (°C):</label>
        <input type="text" id="minTempJan" name="minTempJan" required><br>
        
        <label for="minTempAug">8月极低温度 (°C):</label>
        <input type="text" id="minTempAug" name="minTempAug" required><br>
        
        <label for="avgTempJul">7月平均温度 (°C):</label>
        <input type="text" id="avgTempJul" name="avgTempJul" required><br>
        
        <input type="submit" value="预测发生量">
    </form>

    <%
        // 检查是否为 POST 请求
        if ("POST".equalsIgnoreCase(request.getMethod())) {
            try {
                // 获取用户输入
                String precipitationStr = request.getParameter("precipitation");
                String humidityStr = request.getParameter("humidity");
                String maxTempJanStr = request.getParameter("maxTempJan");
                String minTempJanStr = request.getParameter("minTempJan");
                String minTempAugStr = request.getParameter("minTempAug");
                String avgTempJulStr = request.getParameter("avgTempJul");

                // 确保所有参数不为 null
                if (precipitationStr != null && humidityStr != null && maxTempJanStr != null &&
                    minTempJanStr != null && minTempAugStr != null && avgTempJulStr != null) {

                    double precipitation = Double.parseDouble(precipitationStr);
                    double humidity = Double.parseDouble(humidityStr);
                    double maxTempJan = Double.parseDouble(maxTempJanStr);
                    double minTempJan = Double.parseDouble(minTempJanStr);
                    double minTempAug = Double.parseDouble(minTempAugStr);
                    double avgTempJul = Double.parseDouble(avgTempJulStr);

                    // 创建预测对象并计算发生量
                    LarvaePrediction prediction = new LarvaePrediction();
                    double result = prediction.predict(precipitation, humidity, maxTempJan, minTempJan, minTempAug, avgTempJul);

                    // 显示结果
                    out.println("<h2>预测的发生量: " + result + "</h2>");
                } else {
                    out.println("<h2>请确保所有输入字段都已填写。</h2>");
                }
            } catch (NumberFormatException e) {
                out.println("<h2>输入格式错误，请确保所有输入都是数字。</h2>");
            } catch (Exception e) {
                out.println("<h2>发生错误: " + e.getMessage() + "</h2>");
            }
        }
    %>
</body>
</html>


