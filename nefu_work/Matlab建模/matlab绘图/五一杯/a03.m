% 设置图形窗口大小
figure('Position',[100 100 800 600]);

% 定义椭圆参数
a = 20; % 长半轴
b = 15; % 短半轴

% 生成椭圆坐标点
theta = linspace(0, 2*pi, 100); % 从0到2π生成100个角度值
x = a * cos(theta); % x坐标
y = b * sin(theta); % y坐标

% 将椭圆平移到(0,0)
x = x + 0; % x坐标平移到0
y = y + 0; % y坐标平移到0

% 绘制椭圆
plot(x, y, 'b-', 'LineWidth', 2);
hold on; % 保持当前图像

% 计算x轴和y轴的长度
x_max = max(abs(x));
y_max = max(abs(y));
axis_length = max(x_max, y_max) * 2.4; % 将轴长设为最大值的2.4倍

% 绘制坐标轴
plot([-axis_length axis_length], [0 0], 'k-', 'LineWidth', 1); % x轴
plot([0 0], [-axis_length axis_length], 'k-', 'LineWidth', 1); % y轴

% 添加五个点
O = [0 0];

P2=[11 11];
P3=[-12 11];
P4=[-6 -11];
P5=[14 -9];

Q2=[11.6 12.2];
Q3=[-12.4 11.7];
Q4=[-6.8 -14.1];
Q5=[14.8 -10.0];

% 绘制九个点及其标注
plot(O(1), O(2), 'ro', 'MarkerSize', 3, 'LineWidth', 2, 'MarkerFaceColor', 'r');
text(O(1), O(2) , 'O', 'FontSize', 12, 'FontWeight', 'bold');
plot(P2(1), P2(2), 'ro', 'MarkerSize', 3, 'LineWidth', 2, 'MarkerFaceColor', 'r');
text(P2(1), P2(2) - 0.2, 'P2', 'FontSize', 12, 'FontWeight', 'bold');
plot(P3(1), P3(2), 'ro', 'MarkerSize', 3, 'LineWidth', 2, 'MarkerFaceColor', 'r');
text(P3(1)+0.1, P3(2)-1, 'P3', 'FontSize', 12, 'FontWeight', 'bold');
plot(P4(1), P4(2)+0.2, 'ro', 'MarkerSize', 3, 'LineWidth', 2, 'MarkerFaceColor', 'r');
text(P4(1), P4(2) + 1, 'P4', 'FontSize', 12, 'FontWeight', 'bold');
plot(P5(1), P5(2), 'ro', 'MarkerSize', 3, 'LineWidth', 2, 'MarkerFaceColor', 'r');
text(P5(1), P5(2) + 1, 'P5', 'FontSize', 12, 'FontWeight', 'bold');

plot(Q2(1), Q2(2), 'ro', 'MarkerSize', 3, 'LineWidth', 2, 'MarkerFaceColor', 'r');
text(Q2(1), Q2(2) + 1, 'Q2', 'FontSize', 12, 'FontWeight', 'bold');
plot(Q3(1), Q3(2), 'ro', 'MarkerSize', 3, 'LineWidth', 2, 'MarkerFaceColor', 'r');
text(Q3(1)-0.4, Q3(2)+1, 'Q3', 'FontSize', 12, 'FontWeight', 'bold');
plot(Q4(1), Q4(2), 'ro', 'MarkerSize', 3, 'LineWidth', 2, 'MarkerFaceColor', 'r');
text(Q4(1)-0.5, Q4(2)-1, 'Q4', 'FontSize', 12, 'FontWeight', 'bold');
plot(Q5(1),Q5(2), 'ro', 'MarkerSize', 3, 'LineWidth', 2, 'MarkerFaceColor', 'r');
text(Q5(1), Q5(2)-0.2, 'Q5', 'FontSize', 12, 'FontWeight', 'bold');

% 连接Pi和Qi
plot([P2(1) Q2(1)], [P2(2) Q2(2)], 'r-', 'LineWidth', 2);
plot([P3(1) Q3(1)], [P3(2) Q3(2)], 'r-', 'LineWidth', 2);
plot([P4(1) Q4(1)], [P4(2) Q4(2)], 'r-', 'LineWidth', 2);
plot([P5(1) Q5(1)], [P5(2) Q5(2)], 'r-', 'LineWidth', 2);

% 设置坐标轴等属性
axis equal; % 保持横纵坐标比例一致
grid on; % 显示网格线
xlabel('x轴'); % X轴标签
ylabel('y轴'); % Y轴标签
title('局部区域3'); % 图形标题
