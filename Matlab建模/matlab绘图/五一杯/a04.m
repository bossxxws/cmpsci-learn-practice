% 创建平面直角坐标系
figure;
axis equal;
xlabel('X');
ylabel('Y');
grid on;

% 绘制坐标轴
line([-20 60], [0 0], 'Color', 'k', 'LineWidth', 2); % X轴
line([0 0], [-20 70], 'Color', 'k', 'LineWidth', 2); % Y轴

% 标注点B3(0,50)
hold on;
plot(0, 50, 'ro', 'MarkerFaceColor', 'r', 'MarkerSize', 4, 'LineWidth', 2);
text(-3, 50, 'B3(0,50)', 'FontSize', 10, 'HorizontalAlignment', 'center');

% 标注点B4(40,0)
plot(40, 0, 'ro', 'MarkerFaceColor', 'r', 'MarkerSize', 4, 'LineWidth', 2);
text(40, -1, 'B4(40,0)', 'FontSize', 10, 'HorizontalAlignment', 'center');

% 标注点O(0,0)
plot(0, 0, 'ro', 'MarkerFaceColor', 'r', 'MarkerSize', 4, 'LineWidth', 2);
text(2, -1, 'O(0,0)', 'FontSize', 10, 'HorizontalAlignment', 'center');

% 标注点Q(20,25)
plot(20, 25, 'ro', 'MarkerFaceColor', 'r', 'MarkerSize', 5, 'LineWidth', 2);
text(23, 25, 'Q(20,25)', 'FontSize', 10, 'HorizontalAlignment', 'center');

% 标注点(20,0)
plot(20, 0, 'ro', 'MarkerFaceColor', 'r', 'MarkerSize', 4, 'LineWidth', 2);
text(20, -1, '(20,0)', 'FontSize', 10, 'HorizontalAlignment', 'center');

% 连接O和Q
plot([0 20], [0 25], 'b-', 'LineWidth', 2);

% 连接B3和B4
plot([0 40], [50 0], 'b-', 'LineWidth', 2);

% 连接Q和(20,0)
plot([20 20], [25 0], '--r', 'LineWidth', 2);


%A4 20 15
plot(20, 15, 'ro', 'MarkerFaceColor', 'r', 'MarkerSize', 4, 'LineWidth', 2);
text(23, 15, 'A4(20,15)', 'FontSize', 10, 'HorizontalAlignment', 'center');


%A3 20 35

plot(20, 35, 'ro', 'MarkerFaceColor', 'r', 'MarkerSize', 4, 'LineWidth', 2);
text(23, 35, 'A3(20,35)', 'FontSize', 10, 'HorizontalAlignment', 'center');

% 连接两点
plot([20 20], [15 35], 'b-', 'LineWidth', 2);

% 调整坐标轴范围
axis([-20 60 -20 70]);
