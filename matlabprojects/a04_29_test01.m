% 1.赋值语句

a=1; %#ok<NASGU>

a=2;

% 2.清空工作区变量

% clear

% 3.清屏

% clc

% 5.注释快捷键 ctrl + R

% 6.取消注释快捷键 ctrl + T

% 7.输出函数disp

disp("i am black")

clear

% 8.输入函数input

% a=input("请输入考试分数");
% 
% if a>85
%     disp("大于85")
% end

% 9.字符串合并

s="i am ";
t="matlab";

k=strcat(s,t);

disp(k);

% 10.sum函数求和
    
disp("矩阵的求和")

% 如果是向量，默认是求和
% 如果是矩阵，则需要指明是按行或者是按列求和

E=[1,2,3;4,5,6;7,8,9];

disp(sum(E(:)));
disp(sum(E,1))%按列求和（得到一个行向量）
disp(sum(E,2))%按行求和（得到一个列向量）

% 矩阵的查询

disp(E(3,2));%访问第三行第二个元素

x=[1,2,3,4;3,4,5,6];


disp(x(1,:));

disp(x(:,1));

disp(x(:,[1:3])); %#ok<NBRAK>

clear;

x=[1,2;3,4];

q=inv(x);%求x的逆矩阵

disp(q)

disp(sum(q*x));

% 定义x坐标
x = -10:0.01:10;

% 计算y坐标
y = x.^2;

% 绘制抛物线
plot(x, y)

% 设置坐标轴范围
xlim([-10 10])
ylim([0 100])

% 添加标题和坐标轴标签
title('抛物线')
xlabel('x')
ylabel('y')

% 显示图形
hold on

clear

t1 = 0:0.1:10;
v1 = t1;

t2 = 10:0.1:20;
v2 = 0 * t2 + 10;

t3 = 20:0.1:30;
v3 = 30 - t3;

t = [t1 t2 t3];
v = [v1 v2 v3];

plot(t, v);
axis([0 32 0 12]);

%对于矩阵 *是矩阵之间的乘法,比如A/B=A*（inv（B））

%对于每个元素之间的乘法要用.*，./

%例如：

A=[1,2];

A=A.^2;

disp(A);

%求特征值

A=[1,2,3;2,2,1;2,0,3];

% E=elg(A);

% [V,D]=elg(A);

