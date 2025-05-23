<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html lang="zh">
<head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Web学习网站</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 0;
            background-color: #f4f4f4;
        }
        header {
            background-color: #4CAF50;
            color: white;
            text-align: center;
            padding: 10px 0;
        }
        nav {
            background-color: #333;
            overflow: hidden;
            text-align:center;
        }
        nav a {
            float: left;
            display: block;
            color: white;
            text-align: center;
            padding: 14px 16px;
            text-decoration: none;
        }
        nav a:hover {
            background-color: #ddd;
            color: black;
            text-align:center;            
        }
        .container {
            display: flex;
        }
        .content {
            width: 100%;
            padding: 15px;
            background-color: white;
        }
        footer {
            background-color: #4CAF50;
            color: white;
            text-align: center;
            padding: 10px 0;
            position: relative;
            bottom: 0;
            width: 100%;
        }
        .marquee {
            background-color: #ffcc00;
            padding: 10px;
            color: black;
            font-weight: bold;
            white-space: nowrap;
            overflow: hidden;
            box-sizing: border-box;
        }
        .marquee div {
            display: inline-block;
            animation: marquee 10s linear infinite;
        }
        @keyframes marquee {
            0% { transform: translateX(100%); }
            100% { transform: translateX(-100%); }
        }
    </style>
</head>
<body>

<header>
    <h1>数据结构与算法学习网站</h1>
</header>

<nav>
    <a href="#">首页</a>
    <a href="#">课程章节</a>
    <a href="#">教师团队</a>
    <a href="#">教学资源</a>
    <a href="#">教学方法</a>
    <a href="#">教学条件</a>
    <a href="#">参考教材</a>
</nav>

<div class="marquee">
    <div>欢迎来到数据结构与算法学习网站！请查看我们的课程和资源。</div>
</div>


<div class="container">
    <div class="image">
        <img src="0201.png" alt="学习内容图片" style="width: 100%; height: auto;">
    </div>
    <div class="content">
        <h2>数据结构与算法简介</h2>
        <p  style=font-weight:bold >
数据结构和算法是计算机科学的两个基本概念，密切相关，构成了程序设计的基础。

数据结构
数据结构是指在计算机中组织、存储和管理数据的方式。它们提供了高效的数据存取和修改方法。常见的数据结构包括：

数组：固定大小的线性数据结构，支持快速访问。
链表：由节点组成的线性数据结构，每个节点包含数据和指向下一个节点的指针。
栈：后进先出（LIFO）的数据结构，支持在一端插入和删除元素。
队列：先进先出（FIFO）的数据结构，支持在一端插入元素，在另一端删除元素。
树：层次结构的数据结构，常用于表示分层关系，如二叉树、平衡树等。
图：由节点和边组成的数据结构，用于表示复杂关系。
算法
算法是解决特定问题的一系列步骤或规则。它们可以是简单的，如排序和查找，也可以是复杂的，如图遍历和动态规划。算法的效率通常通过时间复杂度和空间复杂度来衡量。

常见的算法包括：

排序算法：如快速排序、归并排序和冒泡排序。
搜索算法：如二分搜索和深度优先搜索（DFS）、广度优先搜索（BFS）。
动态规划：通过将问题分解为子问题来求解最优解的技术。
贪心算法：通过局部最优选择来构建全局最优解的策略。
总结
数据结构和算法是编程的基石，选择合适的数据结构和算法可以显著提高程序的性能和效率。掌握它们对于软件开发和计算机科学研究至关重要。
		</p>
    </div>
</div>

<footer>
    <p>张奥 2024-09-28</p>
</footer>

</body>
</html>
