<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">

<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>计时器示例</title>
    <script>
        var startTime = new Date().getTime(); // 获取当前时间的时间戳
        var twoHoursInMilliseconds = 2 * 60 * 60 * 1000; // 2小时转换成毫秒

        function startCountdown() {
            var now = new Date().getTime();
            var distance = twoHoursInMilliseconds - (now - startTime);

            // 计算小时、分钟和秒
            var hours = Math.floor((distance % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60));
            var minutes = Math.floor((distance % (1000 * 60 * 60)) / (1000 * 60));
            var seconds = Math.floor((distance % (1000 * 60)) / 1000);

            // 格式化时间显示，确保总是两位数字
            var formattedTime = hours.toString().padStart(2, '0') + ":" +
                                minutes.toString().padStart(2, '0') + ":" +
                                seconds.toString().padStart(2, '0');

            // 显示时间
            document.getElementById("timer").textContent = formattedTime;

            // 如果时间到了，停止计时器
            if (distance < 0) {
                clearInterval(x);
                document.getElementById("timer").textContent = "02:00:00";
                alert('2小时时间到！');
            } else {
                // 每1000毫秒（1秒）调用一次这个函数
                var x = setTimeout(startCountdown, 1000);
            }
        }
    </script>
</head>
<body onload="startCountdown();">
    <h1>正计时器</h1>
    <div id="timer">00:00:00</div>
</body>
</html>