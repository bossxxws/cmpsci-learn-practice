<%@ page language = "java" import="java.util.*" pageEncoding="utf-8"%>
<%
    String path = request.getContextPath();
    String basePath = request.getScheme() + "://"
            + request.getServerName() + ":"
            + request.getServerPort() + path + "/";

%>
<!DOCTYPE html>
<html lang="en">
<head>
  	<base href="<%=basePath%>">
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>忘记密码</title>
    <link rel="stylesheet" href="../css/bootstrap.css">
    <link rel="stylesheet" href="../css/base.css">
    <script src="../js/jquery-1.10.2.js"></script>
    <script src="../js/bootstrap.js"></script>
    <script src="../js/base.js"></script>
    <style type="text/css">
    	.modalfom{
    		display: none;
    	}
    	.forget{
    		display: block;
    	}
    </style>
    <script type="text/javascript">
    	$(function(){		
    		$("#but1").click(function(){
    			if($("#user").val()!=""){
    				//根据用户名查询
    				$.ajax({
    					url:"admin/queryAdminInfoByName",
    					type:"post",
    					dataType:"json",
    					data:{
    						adminName:$("#user").val()
    					},
    					success:function(result){
    						if(result.message=="success"){
    							$(".modalfom").hide();
    							$(".tipscode").show();
    							
    							$(".adminName").html(result.obj.adminName);
    							
    							var phone =result.obj.phone;
    							var phoneLength = phone.length;
    							$("#phone").html("******"+phone.substring(phoneLength-4,phoneLength));
    							
    							$("#id").val(result.obj.id);
    							$("#telephone").val(result.obj.phone);
    						}else{
    							$(".msg").eq(0).text("对不起，当前用户不存在")
    						}
    					}
    				});
    				
    			}else{
    				$(".msg").eq(0).text("用户名不允许为空")
    			}
    		});
    		
    		
    		$("#createCode").click(function(){
    			//生成验证码
				$.ajax({
					url:"/home/createMsgCode",
					type:"post",
					dataType:"json",
					data:{
						phone:$("#telephone").val()
					},
					success:function(result){
						if(result.message=="success"){
							var num=60
							$("#createCode").attr("disabled",true);    													
							var t=setInterval(function() {
								if(num<=0){
									$("#createCode").html("获得验证码");
									$("#createCode").attr("disabled",false); 
									clearInterval(t)
									return;
								}
								$("#createCode").html(num--+"秒")   
								   								
							}, 1000);
						}else{
							$(".msg").eq(1).text("发送失败")
						}
					}
				});
    		});
    		
    		
    		//验证验证码
    		$("#but2").click(function(){
    			if($("#code").val()!=""){
    				$.ajax({
    					url:"/home/verifyMsgCode",
    					type:"post",
    					dataType:"json",
    					data:{
    						msgCode:$("#code").val()
    					},
    					success:function(result){
    						if(result.message=="success"){ //通过
    							$(".modalfom").hide();
    							$(".setpass").show();
    						}else if(result.message=="delayed"){ //过期
    							$(".msg").eq(1).text("验证码已过期，请重新发送")
    							$("#code").html("");
    						}else if(result.message=="error"){ //验证未通过
    							$(".msg").eq(1).text("验证码不正确")
    							$("#code").html("");
    						}
    					}
    				});
    			}else{
    				$(".msg").eq(1).text("验证码不允许为空")
    			}
    		});
    		
    		$("#but3").click(function(){
    			var password=$("#password").val();    
    			var password1=$("#password1").val();
    			var reg=/^(.){6,20}$/;
    			if(password==""){
    				$(".msg").eq(2).text("密码不允许为空")
    			}
    			else if(reg.test(password)==false){
    				$(".msg").eq(2).text("不符合规则，满足6-20位")
    			}
    			else if(password!=password1){
    				$(".msg").eq(2).text("两次密码输入不一致")
    			}
    			else{
    					//修改密码
    					$.ajax({
    						url:"/admin/updatePwd",
    						type:"post",
    						dataType:"json",
    						data:{
    							id:$("#id").val(),
    							password:password
    						},
    						success:function(result){
    							if(result.message=="success"){    
    								$(".modalfom").hide()
    								$(".success").show()
    							}else{
    								$(".msg").eq(2).text("修改失败")
    							}
    						}
    					});
    				}
    		});
    		$("#but4").click(function(){
    			location.href="home_detail/adminlogin.jsp"
    		})
    	});
    </script>
</head>
<body>
 	<!--头部-->
     <div id="header"> 
        <div  class="container" >
         <div class="row" >
             <div class="col-lg-5 col-md-12 col-xs-12 title"  >
                 <img src="../img/title.png" class="img-responsive">
             </div>
             <div class="col-lg-7 col-md-12 col-xs-12 ">
                 <div class="divm">
                     <div> <object data="../img/u4.svg" width="21" height="21"  class="tel"></object>
                     <div class="ph">
                         <span>服务热线（仅收市话费）</span>
                         <h4>400-0000-000</h4>
                     </div>    </div>           
                 </div>  
                 <div class="login">                               
                     <a href="login.jsp">
                         <svg version="1.1" xmlns:xlink="http://www.w3.org/1999/xlink" width="14px" height="16px" xmlns="http://www.w3.org/2000/svg">
                         <g transform="matrix(1 0 0 1 -27 -33 )">
                         <path d="M 13.90703125 11.5677083333333  C 13.9690104166667 12.0920138888889  14 12.6493055555556  14 13.2395833333333  C 14 13.9965277777778  13.7721354166667 14.6458333333333  13.31640625 15.1875  C 12.8606770833333 15.7291666666667  12.3119791666667 16  11.6703125 16  L 2.3296875 16  C 1.68802083333333 16  1.13932291666667 15.7291666666667  0.68359375 15.1875  C 0.227864583333333 14.6458333333333  0 13.9965277777778  0 13.2395833333333  C 0 12.6493055555556  0.0309895833333334 12.0920138888889  0.0929687500000001 11.5677083333333  C 0.154947916666667 11.0434027777778  0.269791666666667 10.515625  0.4375 9.984375  C 0.605208333333334 9.453125  0.818489583333333 8.99826388888889  1.07734375 8.61979166666667  C 1.33619791666667 8.24131944444444  1.67890625 7.93229166666667  2.10546875 7.69270833333333  C 2.53203125 7.453125  3.02239583333333 7.33333333333333  3.5765625 7.33333333333333  C 4.53177083333333 8.22222222222222  5.67291666666667 8.66666666666667  7 8.66666666666667  C 8.32708333333334 8.66666666666667  9.46822916666667 8.22222222222222  10.4234375 7.33333333333333  C 10.9776041666667 7.33333333333333  11.46796875 7.453125  11.89453125 7.69270833333333  C 12.32109375 7.93229166666667  12.6638020833333 8.24131944444444  12.92265625 8.61979166666667  C 13.1815104166667 8.99826388888889  13.3947916666667 9.453125  13.5625 9.984375  C 13.7302083333333 10.515625  13.8450520833333 11.0434027777778  13.90703125 11.5677083333333  Z M 9.96953125 1.171875  C 10.78984375 1.953125  11.2 2.89583333333333  11.2 4  C 11.2 5.10416666666667  10.78984375 6.046875  9.96953125 6.828125  C 9.14921875 7.609375  8.159375 8  7 8  C 5.840625 8  4.85078125 7.609375  4.03046875 6.828125  C 3.21015625 6.046875  2.8 5.10416666666667  2.8 4  C 2.8 2.89583333333333  3.21015625 1.953125  4.03046875 1.171875  C 4.85078125 0.390625  5.840625 0  7 0  C 8.159375 0  9.14921875 0.390625  9.96953125 1.171875  Z " fill-rule="nonzero" fill="#aaaaaa" stroke="none" transform="matrix(1 0 0 1 27 33 )" />
                         </g>
                     </svg>登录</a>
                     <a href="register.html"><svg version="1.1" xmlns:xlink="http://www.w3.org/1999/xlink" width="16px" height="16px" xmlns="http://www.w3.org/2000/svg">
                         <g transform="matrix(1 0 0 1 -27 -33 )">
                         <path d="M 14.1857730263158 14.1857730263158  C 14.1857730263158 14.7159539473684  13.8324177631579 15.0694736842105  13.3020559210526 15  L 1.81414473684211 15  C 1.28388157894737 15.0694736842105  0.930427631578948 14.7159539473684  1 14.1857565789474  L 1 2.69786184210526  C 0.930427631578948 2.16759868421053  1.28388157894737 1.81416118421053  1.81414473684211 1.81416118421053  L 8.88371710526316 1.81416118421053  L 8.88371710526316 0.930427631578947  L 1.81414473684211 0.930427631578947  C 0.842105263157895 0.930427631578947  0.046825657894737 1.72582236842105  0 2.69786184210526  L 0 14.1857730263158  C 0.046825657894737 15.1578947368421  0.842105263157895 15.9531743421053  1.81422697368421 16  L 13.3020559210526 16  C 14.2741940789474 15.9531743421053  15.0694736842105 15.1578947368421  15.0694736842105 14.1857730263158  L 15.0694736842105 7.11628289473684  L 14.1857565789474 7.11628289473684  L 14.1857565789474 14.1857565789474  Z M 13.6315789473684 5.46138157894737  L 10.5251315789474 2.37314144736842  L 3.70745065789474 9.18847039473684  L 3.08893092105263 12.8117105263158  L 6.80042763157895 12.2814309210526  L 13.6315789473684 5.46138157894737  Z M 15.4229934210526 1.19554276315789  L 14.8044407894737 0.576924342105263  C 14.4508388157895 0.223486842105263  14.0090789473684 0.0467434210526316  13.5672203947368 0.0467434210526316  C 13.1252796052632 0.0467434210526316  12.6835197368421 0.223486842105263  12.33 0.577006578947368  L 11.0602631578947 1.84674342105263  L 14.2048190789474 4.88815789473684  L 15.4230098684211 3.66996710526316  C 16.1299506578947 2.96300986842105  16.1299506578947 1.81412828947368  15.4230098684211 1.19552631578947  Z " fill-rule="nonzero" fill="#aaaaaa" stroke="none" transform="matrix(1 0 0 1 27 33 )" />
                         </g>
                     </svg>注册</a>
                 </div>
                 <div class="signedin">
                     <p><img src="../img/notice.jpg" class="hidden-xs">
                     欢迎<img src="../img/vip.jpg" width="27px" height="15px" id="vip"><a href="javascript:void(0);" id="cName">北京市京海换热设备制造有限责任公司</a></p>
                     <div class="btns"> 
                         <button type="button" id="vipbtn" class="btn btn-default  vipbtn">升级企业VIP</button>
                         <button type="button" class="btn btn-default hidden-xs" onclick="qqzx()">在线咨询</button>
                         <button type="button" class="btn btn-default" id="updatepass">修改密码</button>
                         <button type="button" class="btn btn-default" id="out" >退出登陆</button>
                     </div>
                 </div> 
             </div>            
         </div>
        </div>
        <!--菜单-->
     <nav class="navbar navbar-default " role="navigation">
         <div class="container-fluid"> 
         <div class="navbar-header">
            <button type="button" class="navbar-toggle " data-toggle="collapse"
            data-target="#example-navbar-collapse">
                <span class="sr-only">切换导航</span>
                <span class="icon-bar"></span>
                <span class="icon-bar"></span>
                <span class="icon-bar"></span>
            </button>
             
             <div class="clearfix pull-left">                        
                 <a href="adminlogin.jsp" class="pull-right">
                     <img src="../img/logo-logo.png"  width="170px" height="120px">
                 </a>
             </div>
         </div>
         <div class="collapse navbar-collapse pull-right" id="example-navbar-collapse">
             <ul class="nav navbar-nav">
                 <li><a href="index.html">首  页</a></li>
                 <li><a href="purchase.html">商品采购</a></li>
                 <li><a href="supply.html">需求供应</a></li>
                 <li><a href="logistics.html">物流查看</a></li>
                 <li><a href="news.html">业界新闻</a></li>
                 <li><a href="about.html">关于企业</a></li>
             </ul>
         </div>
         </div>
     </nav>
    </div>
    <!--忘记密码 -->   
    <div class="modalfom forget container">
        <h3>忘记密码</h3>
        <form  class="row">
            <div class="form-group">
                <label for="name">请输入要重置密码的用户名</label>
                <input type="text" class="form-control" id="user" name="user" placeholder="请输入要重置密码的用户">
            </div>
            <p class="msg"></p>  
            <div class="row">
                <div class="col-sm-11">
                    <button type="button" id="but1" class="btn btn-primary btn-lg btn-block">下一步</button>
                </div>
            </div>
        </form>
    </div>
    
     <!--输入验证码-->
    <div class="modalfom tipscode container">
        <h3>输入验证码</h3>
        <form  class="row">
            <div class="tips">您正在对<span class="adminName">XXXX</span>进行重置密码操作，请先进行安全验证：</div>
            <div class="form-group">
                <label for="name">点击获取验证码，短信将发送至安全手机<span id="phone">********191</span></label>
                <div class="row">
                	<input type="hidden" id="id">
                	<input type="hidden" id="telephone">
                    <div class="col-sm-8 col-xs-6"><input type="text" name="code" id="code" placeholder="输入验证码"></div>
                    <div class="col-sm-4 col-xs-4"><button type="button" id="createCode" class="btn btn-default">获得验证码</button></div>
                </div>
            </div>
            <p class="msg"></p>  
            <p> 若无法验证，请联系管理员 </p>
            <div class="row">
                <div class="col-sm-11">
                    <button type="button" id="but2" class="btn btn-primary btn-lg btn-block">下一步</button>
                </div>
            </div>
            
        </form>
    </div>   
    <!--设置新密码-->
    <div class="modalfom setpass container">
        <h3>设置新密码</h3>
        <form  class="row">
            <div class="form-group">
                <label >请设置<span class="adminName">XXXX</span>的新密码，建议使用数字、字母、字符的组合密码，提高密码安全等级</label>
                 <div class="pas"><input type="password" class="form-control" name="password" id="password" placeholder="6-20位密码，区分大小写"></div>
                <div class="pas"><input type="password" class="form-control" name="password1" id="password1" placeholder="6-20位密码，区分大小写"></div>
            </div>
            <p class="msg"></p>  
            <div class="row">
                <div class="col-sm-11">
                    <button type="button" id="but3" class="btn btn-primary btn-lg btn-block">确 认</button>
                </div>
            </div>
        </form>
    </div>  
     <!--设置新密码-->
    <div class="modalfom success container">
        <h3>重置密码</h3>
        <div class="row">
            <div class="col-sm-12">
                <img src="../img/success.png">
                <p>重置密码成功</p>
            </div>
            <div class="col-sm-12">
                    <button type="button" class="btn btn-primary btn-lg btn-block" id="but4">确 定</button>
            </div>
        </div>
    </div>  
     <!--底部-->
     <div id="footer">
        <div class="container" > 
            <div class="row">
                <div class="col-md-6 bth">
                   <div class="row">
                    <div class="col-md-6 ph">
                        <img class="wximage" src="../img/wei.png" >
                        <p>微信在线客服</p>
                    </div>
                    <div class="col-md-6 ph">
                        <img class="whatsupimage" src="../img/wei.png" >
                        <p>移动端网站（手机）</p>
                    </div>
                    <input type="hidden" id="qqNo"/>                   
                   </div>
                </div>
                <div class="col-md-6 about">
                    <h4>联系我们 <span>Contact</span> </h4>
                    <div class="row">
                        <div class="col-md-6">
                            <p>地址：黑龙江省哈尔滨市西大直街XXXX号</p>
                            <p>邮编：150000</p>
                            <p>电话：0451-88886666</p>
                        </div>
                        <div class="col-md-6">             
                            <p>手机：18088886666 / 18088886666</p>
                            <p>传真：0451-88886666</p>
                            <p> 邮箱：XXXXXXX@163.com</p>
                        </div>
                    </div>
                </div>
            </div>
        </div>
        <div class="bottom">
            <p>
                <span>CopyRight © 2021</span>    
                <span>国际贸易采购平台</span>
                <span>XXXX.com All Rights Reserved</span>        
                <span>备案：ICP备8888888号</span> 
            </p>
        </div>
    </div>
</body>
</html>