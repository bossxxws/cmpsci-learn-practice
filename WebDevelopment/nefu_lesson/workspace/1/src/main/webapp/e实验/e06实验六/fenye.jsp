<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.sql.*,com.nefu.jdbc.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<table border=1 width=100%>
<tr><th>序号</th><th>姓名</th><th>语文</th><th>数学</th><th>英语</th><th>查询</th><th>修改</th><th>删除</th></tr>
<%
int nowpage=1;
if(request.getParameter("nowpage")!=null){
	try{
nowpage=Integer.parseInt(request.getParameter("nowpage"));}
	catch(NumberFormatException e){
		nowpage=1;
	}
}
int totalpage=0;
int totalrecord=0;
String sql1="select count(*) as totalrecord from user";
dbconn db=new dbconn();
ResultSet rs=null;
Statement stmt=null;
String sql="select * from user";
rs=db.executequery(sql1);
rs.next();
totalrecord=rs.getInt(1);

if(totalrecord%5==0){
	totalpage=totalrecord/5;
}
else{
	totalpage=(int)Math.floor(totalrecord/5)+1;
}





rs=db.executequery(sql);
//while(rs.next()){
	rs.absolute((nowpage-1)*5+1);
for(int i=0;i<5;i++){


	%>
	
<tr><td><%=rs.getString(1) %></td><td><%=rs.getString(2) %></td><td><%=rs.getString(3) %></td><td><%=rs.getString(4) %></td>
<td><%=rs.getString(5) %></td><td>查询</td><td><a href="modify.jsp?id=<%=rs.getString(1) %>">修改</a></td><td>删除</td></tr>
	

	<%
	if(!rs.next())break;	
}
db.connclose();
%>
</table>
<hr>
当前<%=nowpage %>/<%=totalpage %>页
一共有<%=totalrecord %>条记录
<form action="#">请您输入跳转页<input type="text" name="nowpage" size=1>
<input type="submit" value="go">
</form><hr>
<a href="fenye.jsp">首页</a>
<a href="fenye.jsp?nowpage=<%=nowpage-1%>">上一页</a>
<a href="fenye.jsp?nowpage=<%=nowpage+1%>">下一页</a>
<a href="fenye.jsp?nowpage=<%=totalpage%>">尾页</a>
</body>
</html>