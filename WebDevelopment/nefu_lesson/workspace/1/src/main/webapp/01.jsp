<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<script>
	function aa()
	{
		if(form1.gender[0].checked==true)
		{
			alert(form1.gender[0].value)
		}
		else if(form1.gender[1].checked==true)
		{
			alert(form1.gender[1].value)
		}
		else
		{
			alert("您未选择性别")
		}
	}
</script>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
<!-- chapter1 -->
<%
int a=5;
for(int i=1;i<=a;i++)
{%>
<a href=2.jsp?id=<%=i%> target=window_name> 商品 <%=i %></a> <br> <% 
}
%>

<!-- chater 2 -->
<form action="3.jsp" method="post" name="form1">
请您输入用户名：<input type ="text" id="id1" value="默认值" name="id" size=2><br>
请您输入密码：  <input type = "password" name="ps"><br>
请您输入性别：<input type="radio" name = "gender" value="nan">男
<input type="radio" name = "gender" value="nv"> 女 <br>

请输入您的爱好：<input type = "checkbox" name = "hobby" value = "zuqiu">足球
<input type = "checkbox" name = "hobby" value = "paiqiu">排球
<input type = "checkbox" name = "hobby" value = "lanqiu">篮球<br>
<input type="file" name="f1"><br>
<input type="hidden" name="h1" value="h1">
请输入您的籍贯：
<select name="jg" multiple size=2>
<option value="heilongjiang">黑龙江</option>
<option value="jilin">吉林</option>
<option value="liaoning">辽宁</option>
<option value="henan">河南</option> 
</select><br>

<!-- 搭配html表单编辑器可以给输入区域增加小工具(增加控件) -->
<textarea name="bianjiqi" rows="10" cols="10"></textarea>

<!-- 作业： -->
<!-- 写一个黑龙江选了之后有后面的框 -->
<!-- 吉林选了后面也有一个能选城市的框等等 -->

<!-- 这里的文件只是提交文件名，并无法上传文件 -->

<!-- form是表单的容器，看不见摸不着，但是有一个作用域 -->
<!-- 方法一般是get或者post -->
<!-- post 和 get的区别： -->
<!-- post对应的是to post方法 -->
<!-- get对应的是to get方法 -->
<!-- get刷新后自动提交（而且get是显式的提交） -->
<!-- post重复提交有提醒 -->
<!-- 所以一般用post来提交表单 -->
<!-- servlet就是类 -->
<!-- 下一个页面是通过name来找，当前页面是通过id来找 -->
 
<input type="submit" value="重新提交"> <input type="reset">
<input type="button" value="做点啥" onclick="aa()">
<!-- 能选的不能输，防止造成统计学上的难以区分，造成错误 -->
</form>

</body>
</html>