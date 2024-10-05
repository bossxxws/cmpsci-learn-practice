<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<script>
	var arr = new Array(4);
	arr[0] = ['请选择城市'];
	arr[1] = ['哈尔滨','齐齐哈尔','大庆'];
	arr[2] = ['沈阳','大连','鞍山'];
	arr[3] = ['长春','吉林市','四平'];
	
	function changeCity(val){
		//获取城市下拉框
		var selCity = document.getElementById("city");
		
		var cityNodes = selCity.getElementsByTagName("option");
		
		for (var y = 0;y<cityNodes.length;y++){
			selCity.removeChild(cityNodes[y]);
			y--;
		}
		//根据传过来的省会value值找到匹配的城市
		for (var y = 0;y<arr[val].length;y++){
			//创建option标签
			var optionNode = document.createElement("option");
			//设置option标签为城市名
			optionNode.innerHTML=arr[val][y];
			//将optionNode添加到下拉框节点之中
			selCity.appendChild(optionNode);
		}
	}</script>
</head>
<body>
	<select onchange = "changeCity(this.value)">
		<option selected value = "0">-请选择省份-</option>
		<option value = "1">黑龙江</option>
		<option value = "2">辽宁</option>
		<option value = "3">吉林</option>
	</select>
	<select id = "city">
		<option>-请选择城市-</option>
		
	</select>	
</body>
</html>