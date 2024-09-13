clc; clear;
close all;
dt = 0.001;
theta_values = linspace(0, 2*pi, 100); 
radius = 450;                     
x_circle = radius * cos(theta_values);             
y_circle = radius * sin(theta_values);              
for pitch_value = 51:0.000001:54.5
    initial_radius = 16 * pitch_value;  
    increment = pitch_value / (2 * pi);  
    theta_values = linspace(0, -16 * 2 * pi, 1000);  
    r_values = initial_radius + increment * theta_values;
    x_spiral = r_values .* cos(theta_values);
    y_spiral = r_values .* sin(theta_values);
    x_center = (r_values - 30) .* cos(theta_values);
    y_center = (r_values - 30) .* sin(theta_values);
    length1 = 341 - 55; 
    length = 220 - 55;
    initial_velocity = 100;
    save_data = zeros(224, 3);  
    num_members = 224; 
    x_positions = initial_radius * ones(1, num_members); 
    y_positions = zeros(1, num_members); 
    distance_travelled = zeros(1, num_members);
    angle_between = 2 * asin(0.5 * length / initial_radius) * ones(1, num_members); 
    linear_velocity = zeros(1, num_members); 
    angular_velocity = zeros(1, num_members);
    theta_start = 0; 
    theta_end = -16 * 2 * pi;
    theta_values = theta_start * ones(1, num_members); 
    rho_values = initial_radius * ones(1, num_members);
    member_count = 1; 
    angle_between(1) = 2 * asin(0.5 * length1 / initial_radius);
    linear_velocity(1) = initial_velocity; 
    angular_velocity(1) = linear_velocity(1) / initial_radius;
    reach_flag = 0;
    stop_flag = 0;
    max_time = 500;
    for t = 0:dt:max_time 
        if (-theta_values(member_count)) >= angle_between(member_count)
            member_count = member_count + 1;
            if member_count > num_members
                member_count = num_members;
            end
        end
        for i = 1:member_count
            theta_values(i) = theta_values(i) - angular_velocity(i) * dt;
            rho_values(i) = initial_radius + increment * theta_values(i);
            if i == 1
                angle_between(1) = 2 * asin(0.5 * length1 / rho_values(1));
                linear_velocity(1) = initial_velocity;
                angular_velocity(1) = linear_velocity(1) / rho_values(1);
            end
            if i >= 2 
                angle_between(i) = 2 * asin(0.5 * length / rho_values(i));
                linear_velocity(i) = initial_velocity;
                angular_velocity(i) = linear_velocity(i) / rho_values(i);
            end           
            x_positions(i) = rho_values(i) * cos(theta_values(i));
            y_positions(i) = rho_values(i) * sin(theta_values(i));
            
            dy = y_positions(1) - y_positions(2);
            dx = x_positions(1) - x_positions(2);
            dz = sqrt((dx)^2 + (dy)^2);
            beta_angle = acos(15 / sqrt(27.5^2 + 15^2));               
            if dy > 0
                angle_xita = acos(dx / dz);
                x0 = x_positions(1) + 27.5 * cos(angle_xita) - 15 * sin(angle_xita);
                y0 = y_positions(1) + 27.5 * sin(angle_xita) + 15 * cos(angle_xita);
                z0 = sqrt(x0^2 + y0^2);
                angle_xita0 = acos(x0 / z0);
            else
                angle_xita = acos(-dx / dz);
                x0 = x_positions(1) - 27.5 * cos(angle_xita) + 15 * sin(angle_xita);
                y0 = y_positions(1) - 27.5 * sin(angle_xita) - 15 * cos(angle_xita);
                z0 = sqrt(x0^2 + y0^2);
                angle_xita0 = acos(x0 / z0);
            end           
            if (rho_values(1) - 450) < 0.01  
                reach_flag = 1;
            end           
            if z0 <= (rho_values(1) + pitch_value - 30) && (rho_values(1) + pitch_value - 30 - z0 < 0.02) && (-theta_values(1) - theta_start) > 2 * pi 
                stop_flag = 1;
            end           
            if z0 > (rho_values(1) + pitch_value - 30) && (-theta_values(1) - theta_start) > 2 * pi 
                stop_flag = 1;
            end     
            save_data(i, 1) = x_positions(i);
            save_data(i, 2) = y_positions(i);
            save_data(i, 3) = initial_velocity;         
            if stop_flag
                break;
            end
        end
        if stop_flag
            break;
        end
    end
    fprintf('螺距: %.6f\n', pitch_value);
    fprintf('%d\n', reach_flag);
end
