<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html lang="zh">
<head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>歌曲列表</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            background-color: #f0f0f0;
            margin: 20px;
        }
        table {
            width: 100%;
            border-collapse: collapse;
            background-color: #fff;
        }
        th, td {
            border: 1px solid #ddd;
            padding: 8px;
            text-align: center;
        }
        th {
            background-color: #f2a1c0;
        }
    </style>
</head>
<body>
    <table>
      	<tr>
            <th colspan="4">播放器</th>
        </tr>
        <tr>
            <th>编号</th>
            <th>歌曲名称</th>
            <th>在线播放</th>
            <th>点播计数</th>
        </tr>
        <tr>
            <td>1</td>
            <td>Don't break my heart</td>
            <td><a href="#">播放</a></td>
            <td>546</td>
        </tr>
        <tr>
            <td>2</td>
            <td>旺天下</td>
            <td><a href="#">播放</a></td>
            <td>444</td>
        </tr>
        <tr>
            <td>3</td>
            <td>自由飞翔</td>
            <td><a href="#">播放</a></td>
            <td>888</td>
        </tr>
        <tr>
            <td>4</td>
            <td>崂山道士</td>
            <td><a href="#">播放</a></td>
            <td>777</td>
        </tr>
    </table>
</body>
</html>
