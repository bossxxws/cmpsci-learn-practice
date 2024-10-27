<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
    <meta charset="UTF-8">
    <title>购买操作框</title>
    <script>
        var quantity = 0;

        function increase() {
            quantity++;
            updateDisplay();
        }

        function decrease() {
            if (quantity > 0) {
                quantity--;
            }
            updateDisplay();
        }

        function updateDisplay() {
            document.getElementById("quantityDisplay").innerText = quantity;
        }
    </script>
</head>
<body>
    <h2>购买操作框</h2>
    <button onclick="decrease()">-</button>
    <span id="quantityDisplay">0</span>
    <button onclick="increase()">+</button>
</body>
</html>
