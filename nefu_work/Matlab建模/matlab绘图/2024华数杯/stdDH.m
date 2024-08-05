%% STD-DH参数
%定义连杆的D-H参数
%连杆偏移
d1 = 398;
d2 = -0.299;
d3 = 0;
d4 = 556.925;
d5 = 0;
d6 = 165;
%连杆长度
a1 = 168.3;
a2 = 650.979;
a3 = 156.240;
a4 = 0;
a5 = 0;
a6 = 0;
%连杆扭角
alpha1 = pi/2;
alpha2 = 0;
alpha3 = pi/2;
alpha4 = -pi/2;
alpha5 = pi/2;
alpha6 = 0;
%建立机器人模型
%       theta  d        a        alpha    
L1=Link([0     d1       a1       alpha1]);
L2=Link([0     d2       a2       alpha2]);L2.offset = pi/2;
L3=Link([0     d3       a3       alpha3]);
L4=Link([0     d4       a4       alpha4]);
L5=Link([0     d5       a5       alpha5]);
L6=Link([0     d6       a6       alpha6]);
%限制机器人的关节空间
L1.qlim = [(-165/180)*pi,(165/180)*pi];
L2.qlim = [(-95/180)*pi, (70/180)*pi];
L3.qlim = [(-85/180)*pi, (95/180)*pi];
L4.qlim = [(-180/180)*pi,(180/180)*pi];
L5.qlim = [(-115/180)*pi,(115/180)*pi];
L6.qlim = [(-360/180)*pi,(360/180)*pi];
%连接连杆，机器人取名为myrobot
robot=SerialLink([L1 L2 L3 L4 L5 L6],'name','myrobot');
robot.plot([0,0,0,0,0,0]);%输出机器人模型，后面的六个角为输出时的theta姿态
robot.display();%打印出机器人D-H参数表
robot.teach;%展示机器人模型
hold on;
