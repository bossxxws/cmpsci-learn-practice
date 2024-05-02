% 定义线段的端点
x1 = 20:0.1:60;
y1 = 15*ones(size(x1));
x2 = 60;
y2 = 15:0.1:35;
x3 = 60:0.1:20;
y3 = 35*ones(size(x3));
x4 = 20;
y4 = 35:0.1:15;

% 绘制线段
plot(x1, y1);
hold on; % 保持当前图像，以便在同一幅图上绘制后续线段
plot(x2, y2);
plot(x3, y3);
plot(x4, y4);
hold off; % 释放图像，防止后续操作影响当前图像

% 闭合路径
close(gcf);

% 设置图形属性
axis equal; % 设置横纵坐标比例相同
grid on; % 显示网格线
xlabel('x');
ylabel('y');
title('Closed Path with Four Segments');

% 可选：添加图例
legend('Segment 1', 'Segment 2', 'Segment 3', 'Segment 4');