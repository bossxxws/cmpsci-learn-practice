import numpy as np
from scipy.integrate import solve_ivp
import matplotlib.pyplot as plt

# 参数定义
r0 = 8.8  # r0 > 0
a = 0.55  # a > 0
L_prime = 2.86  # 第一节与龙头相连的直线长度
L = 1.65  # 其余节数的直线长度
N = 222
times = np.arange(0, 301, 1)

# 等距螺线方程
def r(theta):
    return r0 + a / (2 * np.pi) * theta

# 微分方程定义
def derivatives(t, y):
    theta1 = y[0]
    theta1_prime = -1 / np.sqrt((r0 + a / (2 * np.pi) * theta1) ** 2 + (a / (2 * np.pi)) ** 2)
    
    # 初始化theta和alpha
    thetas = np.zeros(N)
    alphas = np.zeros(N - 1)
    
    thetas[0] = theta1
    
    for i in range(1, N):
        alphas[i - 1] = np.clip(np.arccos((r(thetas[i - 1])**2 + r(thetas[i - 1] + alphas[i - 1])**2 - (L_prime if i == 1 else L)**2) / 
                                            (2 * r(thetas[i - 1]) * r(thetas[i - 1] + alphas[i - 1]))), 0, np.pi)
        thetas[i] = thetas[i - 1] + alphas[i - 1]
    
    # 计算导数
    alpha_primes = np.zeros(N - 1)
    for i in range(N - 1):
        theta_i = thetas[i]
        L_i = L_prime if i == 0 else L
        
        cos_alpha = (r(theta_i)**2 + r(theta_i + alphas[i])**2 - L_i**2) / (2 * r(theta_i) * r(theta_i + alphas[i]))
        cos_alpha = np.clip(cos_alpha, -1, 1)  # 确保值在[-1, 1]之间
        alpha = np.arccos(cos_alpha)

        # 计算alpha的导数
        alpha_primes[i] = (2 * r(theta_i) - (a / (2 * np.pi)) * y[0] - (a / np.pi) * theta_i * r(theta_i + alpha) * np.cos(alpha)) / \
                           (-2 * r(theta_i) * r(theta_i + alpha) + (a / (2 * np.pi)) - (a / np.pi) * r(theta_i) * np.cos(alpha))

    # 返回导数
    return [theta1_prime] + list(alpha_primes)

# 初始条件
initial_conditions = [0] + [0] * (N - 1)  # theta_1(0) = 0, 其余为0

# 求解微分方程
sol = solve_ivp(derivatives, [0, 300], initial_conditions, t_eval=times)

# 提取结果
theta_values = sol.y[:N]
theta1_prime_values = sol.y[0]

# 计算位置和速度
x_positions = []
y_positions = []
speeds = []

for t in range(len(times)):
    x = 0
    y = 0
    speed = 0
    for i in range(N):
        theta_i = theta_values[i][t]
        r_i = r(theta_i)
        x += r_i * np.cos(theta_i)
        y += r_i * np.sin(theta_i)
        
        if i == 0:
            speed += np.sqrt((r_i * (-np.sin(theta_i) * theta1_prime_values[t]))**2 + (r_i * (np.cos(theta_i) * theta1_prime_values[t]))**2)
        else:
            if i - 1 < len(sol.y[N:]):  # 确保索引在范围内
                alpha_i = sol.y[N - 1 + i - 1][t]  # 获取alpha的值
                r_i_plus_alpha = r(theta_i + alpha_i)
                speed += np.sqrt((r_i_plus_alpha * (-np.sin(theta_i + alpha_i) * theta1_prime_values[t]))**2 + (r_i_plus_alpha * (np.cos(theta_i + alpha_i) * theta1_prime_values[t]))**2)
    
    x_positions.append(x)
    y_positions.append(y)
    speeds.append(speed)

# 输出结果
for i in range(len(times)):
    print(f"Time: {times[i]}, X: {x_positions[i]}, Y: {y_positions[i]}, Speed: {speeds[i]}")

# 可视化结果
plt.figure(figsize=(10, 6))
plt.plot(x_positions, y_positions)
plt.title("龙头及各节位置轨迹")
plt.xlabel("X")
plt.ylabel("Y")
plt.axis('equal')
plt.grid()
plt.show()
