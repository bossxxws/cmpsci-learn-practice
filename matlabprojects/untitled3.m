
% 已知点和线段的坐标
point1 = [80, 0];
line_segment = [20, 60; 15, 15; 35, 35];

% 在路径上生成点2的坐标
point2_x = linspace(20, 60, 100);
point2_y = linspace(15, 35, 100);

% 计算每个候选点与给定点之间的距离
distances = zeros(length(point2_x), 1);
for i = 1:length(point2_x)
    distances(i) = norm([point2_x(i), point2_y(i)] - point1);
end

% 找到距离最短的点
[min_distance, min_index] = min(distances);
optimal_point2 = [point2_x(min_index), point2_y(min_index)];

% 绘图
figure;
hold on;

% 绘制线段路径
plot([line_segment(1, 1) line_segment(2, 1)], [line_segment(1, 2) line_segment(1, 2)], 'k', 'LineWidth', 2);
plot([line_segment(1, 1) line_segment(2, 1)], [line_segment(2, 2) line_segment(2, 2)], 'k', 'LineWidth', 2);
plot([line_segment(1, 1) line_segment(1, 1)], [line_segment(1, 2) line_segment(2, 2)], 'k', 'LineWidth', 2);
plot([line_segment(2, 1) line_segment(2, 1)], [line_segment(1, 2) line_segment(2, 2)], 'k', 'LineWidth', 2);

% 绘制第一个点
plot(point1(1), point1(2), 'ro', 'MarkerSize', 8, 'MarkerFaceColor', 'r');

% 绘制点2的路径
plot(point2_x, point2_y, 'b-', 'LineWidth', 2);

% 绘制最短距离的点
plot(optimal_point2(1), optimal_point2(2), 'bo', 'MarkerSize', 8, 'MarkerFaceColor', 'b');

% 绘制两点之间的连线
plot([point1(1) optimal_point2(1)], [point1(2) optimal_point2(2)], 'g--', 'LineWidth', 1.5);

% 设置图形属性
title('最终路线和第二个点的路径');
xlabel('x');
ylabel('y');
legend('线段路径', '第一个点', '第二个点的路径', '最短距离的点', '两点之间的连线');
axis equal;
grid on;
hold off;

% 计算点到线段的距离
function distance = point_to_line_segment_distance(point, line_segment)
    x1 = line_segment(1, 1);
    x2 = line_segment(2, 1);
    y1 = line_segment(1, 2);
    y2 = line_segment(2, 2);

    x0 = point(1);
    y0 = point(2);

    numerator = abs((y2 - y1) * x0 - (x2 - x1) * y0 + x2 * y1 - y2 * x1);
    denominator = sqrt((y2 - y1)^2 + (x2 - x1)^2);

    distance = numerator / denominator;
end
