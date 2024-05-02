% 已知点和线段的坐标
point1 = [80, 0];
line_segment = [20, 60; 15, 15; 35, 35];



% 在路径上生成候选点
candidate_points = [];
for x = 20:60
    candidate_points = [candidate_points; x, 15];
    candidate_points = [candidate_points; x, 35];
end
for y = 15:35
    candidate_points = [candidate_points; 20, y];
    candidate_points = [candidate_points; 60, y];
end

% 计算每个候选点与给定点之间的距离
distances = zeros(size(candidate_points, 1), 1);
for i = 1:size(candidate_points, 1)
    distances(i) = norm(candidate_points(i, :) - point1);
end

% 找到距离最短的点
[min_distance, min_index] = min(distances);
optimal_point = candidate_points(min_index, :);

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

% 绘制最短距离的点
plot(optimal_point(1), optimal_point(2), 'bo', 'MarkerSize', 8, 'MarkerFaceColor', 'b');

% 绘制两点之间的连线
plot([point1(1) optimal_point(1)], [point1(2) optimal_point(2)], 'g--', 'LineWidth', 1.5);

% 设置图形属性
title('最终路线和第二个点的路径');
xlabel('x');
ylabel('y');
legend('线段路径', '第一个点', '最短距离的点', '两点之间的连线');
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
