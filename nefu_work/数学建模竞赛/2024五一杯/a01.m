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
P = [25 10];
Q = [18.3 6];
M = [32 0];
N = [20 0];

% 绘制五个点及其标注
plot(O(1), O(2), 'ro', 'MarkerSize', 3, 'LineWidth', 2, 'MarkerFaceColor', 'r');
text(O(1), O(2) + 1, 'O', 'FontSize', 12, 'FontWeight', 'bold');
plot(P(1), P(2), 'ro', 'MarkerSize', 3, 'LineWidth', 2, 'MarkerFaceColor', 'r');
text(P(1), P(2) + 1, 'P', 'FontSize', 12, 'FontWeight', 'bold');
plot(Q(1), Q(2), 'ro', 'MarkerSize', 3, 'LineWidth', 2, 'MarkerFaceColor', 'r');
text(Q(1), Q(2) + 1, 'Q', 'FontSize', 12, 'FontWeight', 'bold');
plot(M(1), M(2), 'ro', 'MarkerSize', 3, 'LineWidth', 2, 'MarkerFaceColor', 'r');
text(M(1), M(2) + 1, 'M', 'FontSize', 12, 'FontWeight', 'bold');
plot(N(1), N(2), 'ro', 'MarkerSize', 3, 'LineWidth', 2, 'MarkerFaceColor', 'r');
text(N(1), N(2) + 1, 'N', 'FontSize', 12, 'FontWeight', 'bold');

% 连接P和Q
plot([P(1) Q(1)], [P(2) Q(2)], 'r-', 'LineWidth', 2);

% 设置坐标轴等属性
axis equal; % 保持横纵坐标比例一致
grid on; % 显示网格线
xlabel('x轴'); % X轴标签
ylabel('y轴'); % Y轴标签
title('局部区域1'); % 图形标题
