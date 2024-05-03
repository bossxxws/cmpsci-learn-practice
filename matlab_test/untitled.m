%已知点坐标为（80, 0），已知线段为y=15(20<x<60), y=35(20<x<60), x=20(15<y<35),x=60(15<y<35)

% 已知点和线段的坐标
known_points = [80 0; 20 15; 20 35; 60 15; 60 35];

% 参数设置
initial_point = [50 25]; % 初始点
initial_temperature = 100; % 初始温度
cooling_rate = 0.95; % 温度衰减率
iterations = 1000; % 迭代次数

% 运行模拟退火算法
best_point = simulated_annealing(initial_point, initial_temperature, cooling_rate, iterations);

fprintf('最优点的坐标：(%.4f, %.4f)\n', best_point);
fprintf('最小距离之和：%.4f\n', objective_function(best_point));

% 目标函数：计算已知点到目标点的距离之和
function total_distance = objective_function(point)
    global known_points
    total_distance = sum(sqrt((known_points(:,1) - point(1)).^2 + (known_points(:,2) - point(2)).^2));
end

% 模拟退火算法
function best_point = simulated_annealing(initial_point, initial_temperature, cooling_rate, iterations)
    current_point = initial_point;
    current_temperature = initial_temperature;

    for i = 1:iterations
        % 生成新的解
        new_point = current_point + randn(1, 2) * 0.1;

        % 计算目标函数值的变化
        delta = objective_function(new_point) - objective_function(current_point);

        % 如果新解更优或按照一定概率接受较差解
        if delta < 0 || rand < exp(-delta / current_temperature)
            current_point = new_point;
        end

        % 降低温度
        current_temperature = current_temperature * cooling_rate;
    end

    best_point = current_point;
end


