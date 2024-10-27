<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">

<html lang="zh">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>表格隔行换色</title>
    <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
    <style>
        table {
            width: 100%;
            border-collapse: collapse;
        }
        th, td {
            border: 1px solid #ddd;
            padding: 8px;
            text-align: left;
        }
        tr:nth-child(even) {
            background-color: #f2f2f2; /* 隔行换色 */
        }
        tr:hover {
            background-color: #d1e7dd; /* 鼠标指向变色 */
        }
    </style>
</head>
<body>
    <h1>表格隔行换色示例</h1>
    <table>
        <thead>
            <tr>
                <th>姓名</th>
                <th>年龄</th>
                <th>城市</th>
            </tr>
        </thead>
        <tbody>
            <tr>
                <td>张三</td>
                <td>25</td>
                <td>北京</td>
            </tr>
            <tr>
                <td>李四</td>
                <td>30</td>
                <td>上海</td>
            </tr>
            <tr>
                <td>王五</td>
                <td>28</td>
                <td>广州</td>
            </tr>
            <tr>
                <td>赵六</td>
                <td>35</td>
                <td>深圳</td>
            </tr>
            <tr>
                <td>周七</td>
                <td>22</td>
                <td>成都</td>
            </tr>
        </tbody>
    </table>
</body>
</html>
