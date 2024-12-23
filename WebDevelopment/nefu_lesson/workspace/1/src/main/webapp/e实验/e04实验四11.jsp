<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">


<html lang="zh">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>动态横向菜单示例</title>
    <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
    <style>
        body {
            font-family: Arial, sans-serif;
        }
        #menu {
            list-style-type: none;
            padding: 0;
            display: flex; /* 使用flex布局 */
            justify-content: space-around; /* 均匀分布 */
            background-color: #f2f2f2;
            margin-bottom: 20px;
        }
        #menu li {
            cursor: pointer;
            padding: 15px 20px;
        }
        #menu li:hover {
            background-color: #ddd; /* 鼠标悬停效果 */
        }
        .table-container {
            display: none;
            margin-top: 20px;
        }
        table {
            width: 100%;
            border-collapse: collapse;
        }
        th, td {
            border: 1px solid #ddd;
            padding: 8px;
            text-align: left;
        }
        th {
            background-color: #f2f2f2;
        }
    </style>
</head>
<body>

<h1>动态横向菜单</h1>
<ul id="menu">
    <li data-target="#appliances">家电</li>
    <li data-target="#clothing">服装</li>
</ul>

<div id="appliances" class="table-container">
    <h2>家电</h2>
    <table>
        <tr>
            <th>产品</th>
            <th>价格</th>
        </tr>
        <tr>
            <td>冰箱</td>
            <td>3000元</td>
        </tr>
        <tr>
            <td>洗衣机</td>
            <td>1500元</td>
        </tr>
    </table>
</div>

<div id="clothing" class="table-container">
    <h2>服装</h2>
    <table>
        <tr>
            <th>产品</th>
            <th>价格</th>
        </tr>
        <tr>
            <td>T恤</td>
            <td>100元</td>
        </tr>
        <tr>
            <td>牛仔裤</td>
            <td>200元</td>
        </tr>
    </table>
</div>

<script>
    $(document).ready(function() {
        $('#menu li').click(function() {
            var target = $(this).data('target');
            $('.table-container').hide(); // 隐藏所有表格
            $(target).show(); // 显示对应的表格
        });
    });
</script>

</body>
</html>
