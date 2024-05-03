% 定义初始温度、温度下降率和终止温度
initial_temperature = 100;
cooling_rate = 0.99;
min_temperature = 1;

% 定义初始解（路径上的一个点）
initial_solution = [40, 25]; % 可以根据实际情况修改初始解

% 定义目标函数（点1到路径上的点2的距离）
calculate_distance = @(point1, point2) norm(point1 - point2);

% 定义邻域操作函数（在路径上的相邻点之间进行随机移动）
generate_neighbor = @(current_solution) current_solution + randn(1, 2);

% 初始化当前解和当前温度
current_solution = initial_solution;
current_temperature = initial_temperature;

% 循环直到达到终止温度
while current_temperature > min_temperature
    % 生成邻域解
    neighbor_solution = generate_neighbor(current_solution);
    
    % 计算目标函数值的变化
    current_distance = calculate_distance([80, 0], current_solution);
    neighbor_distance = calculate_distance([80, 0], neighbor_solution);
    delta_distance = neighbor_distance - current_distance;
    
    % 根据Metropolis准则接受或拒绝邻域解
    if delta_distance < 0 || rand < exp(-delta_distance / current_temperature)
        current_solution = neighbor_solution;
    end
    
    % 降低温度
    current_temperature = current_temperature * cooling_rate;
end

% 打印最终结果
disp(['最短距离：', num2str(calculate_distance([80, 0], current_solution))]);
disp(['最短路径上的点：', num2str(current_solution)]);


% 定义路径的四条边
x1 = 20:0.1:60;
y1 = ones(size(x1)) * 15;

x2 = 20:0.1:60;
y2 = ones(size(x2)) * 35;

y3 = 15:0.1:35;
x3 = ones(size(y3)) * 20;

y4 = 15:0.1:35;
x4 = ones(size(y4)) * 60;

% 绘制路径的四条边
plot(x1, y1, 'b', 'LineWidth', 2);
axis([0,80,0,50]);
hold on;
plot(x2, y2, 'b', 'LineWidth', 2);
axis([0,80,0,50]);
plot(x3, y3, 'b', 'LineWidth', 2);
axis([0,80,0,50]);
plot(x4, y4, 'b', 'LineWidth', 2);
axis([0,80,0,50]);
% 绘制起点和终点
plot(80, 0, 'ro', 'MarkerSize', 10, 'MarkerFaceColor', 'r'); % 起点
plot(current_solution(1), current_solution(2), 'go', 'MarkerSize', 10, 'MarkerFaceColor', 'g'); % 终点

% 绘制最短路径
plot([80, current_solution(1)], [0, current_solution(2)], 'k--', 'LineWidth', 2);
axis([0,80,0,50]);
% 设置图形属性
xlabel('x');
ylabel('y');

title('最短路径');
legend('路径', '起点', '终点', '最短路径');
axis([0,80,0,50]);
grid on;
