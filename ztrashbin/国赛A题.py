import numpy as np
from scipy.optimize import fsolve

import pandas as pd

data = []

# 已知的参数
r0 = 8.8  # r0 > 0
a = 0.55  # a > 0
times = range(0, 301)  # 时间数据列表，取整数
n = 100  # 子区间数目，建议使用偶数
theta0 = -10  # 初始猜测值
L_prime = 2.86  # 第一节与龙头相连的直线长度
L = 1.65  # 其余节数的直线长度
N = 222  # 节数量

# 定义被积函数
def f(x, r0, a):
    return np.sqrt((r0 + (a / (2 * np.pi)) * x)**2 + (a / (2 * np.pi))**2)

# 复化辛普森求积公式
def composite_simpson(a, b, n, r0, a_value):
    h = (b - a) / n
    sum_odd = 0
    sum_even = 0
    for i in range(1, n // 2 + 1):
        sum_odd += f(a + (2 * i - 1) * h, r0, a_value)
    for i in range(1, n // 2):
        sum_even += f(a + 2 * i * h, r0, a_value)
    integral_approx = (h / 3) * (f(a, r0, a_value) + 4 * sum_odd + 2 * sum_even + f(b, r0, a_value))
    return integral_approx

# 牛顿法迭代函数
def newton_method(t, r0, a, theta0, n, tol=1e-6, max_iter=100):
    theta = theta0
    for _ in range(max_iter):
        F_theta = composite_simpson(theta, 0, n, r0, a) - t
        F_prime_theta = -f(theta, r0, a)
        if np.abs(F_prime_theta) < 1e-12:
            raise ValueError("Zero derivative. No solution found.")
        theta_new = theta - F_theta / F_prime_theta
        if np.abs(theta_new - theta) < tol:
            return theta_new
        theta = theta_new
    raise ValueError("Newton method did not converge")

# 螺线方程
def r_theta(theta, r0, a):
    return r0 + a / (2 * np.pi) * theta

# 计算位置
def calculate_position(theta, r0, a):
    r_val = r_theta(theta, r0, a)
    x = r_val * np.cos(theta)
    y = r_val * np.sin(theta)
    return x, y, theta

def solve_alpha(theta, L, r0, a):
    def func(alpha):
        r_theta_alpha = r_theta(theta + alpha, r0, a)
        r_theta_val = r_theta(theta, r0, a)
        return (r_theta_alpha ** 2 + r_theta_val ** 2 - L ** 2) / (2 * r_theta_alpha * r_theta_val) - np.cos(alpha)
    alpha_guess = np.pi / 2
    alpha_solution, = fsolve(func, alpha_guess)
    if alpha_solution <= 0 or alpha_solution >= np.pi:
        alpha_solution = np.pi / 2
    return alpha_solution

# 定义计算角度关于时间的导数的函数
def dtheta_dt(t, r0, a, theta0, n, tol=1e-10):
    h = tol
    theta_plus = newton_method(t + h, r0, a, theta0, n, tol)
    theta_minus = newton_method(t - h, r0, a, theta0, n, tol)
    dtheta_dt_approx = (theta_plus - theta_minus) / (2 * h)
    return dtheta_dt_approx

# 定义计算 alpha 关于时间的导数的函数
def dalpha_dt(t, r0, a, theta0, n, L, i, tol=1e-10):
    h = tol
    alpha_plus = solve_alpha(newton_method(t + h, r0, a, theta0, n, tol), L, r0, a)
    alpha_minus = solve_alpha(newton_method(t - h, r0, a, theta0, n, tol), L, r0, a)
    dalpha_dt_approx = (alpha_plus - alpha_minus) / (2 * h)
    return dalpha_dt_approx


# 定义计算速度的函数
def calculate_velocity(t, r0, a, theta0, n, alphas):
    dtheta_dt_0 = dtheta_dt(t, r0, a, theta0, n)
    total_dtheta_dt = dtheta_dt_0
    for alpha in alphas:
        total_dtheta_dt += dalpha_dt(t, r0, a, theta0, n, L, alphas.index(alpha) + 1)

    theta = newton_method(t, r0, a, theta0, n)
    dr_dtheta = a / (2 * np.pi)
    dx_dtheta = dr_dtheta * np.cos(theta) - r_theta(theta, r0, a) * np.sin(theta)
    dy_dtheta = dr_dtheta * np.sin(theta) + r_theta(theta, r0, a) * np.cos(theta)
    velocity = np.sqrt((dx_dtheta * total_dtheta_dt) ** 2 + (dy_dtheta * total_dtheta_dt) ** 2)
    return velocity


# 主循环
for t in times:
    try:
        thetas = []
        alphas = []
        positions = []
        velocities = []
        theta = newton_method(t, r0, a, theta0, n)
        thetas.append(theta)
        x, y, theta_val = calculate_position(theta, r0, a)
        positions.append((x, y, theta_val))

        for i in range(1, N + 1):
            if i == 1:
                alpha = solve_alpha(thetas[-1], L_prime, r0, a)
            else:
                alpha = solve_alpha(thetas[-1], L, r0, a)
            alphas.append(alpha)
            theta = thetas[-1] + alpha
            thetas.append(theta)
            x, y, theta_val = calculate_position(theta, r0, a)
            positions.append((x, y, theta_val))

        # 计算速度
        velocities = [calculate_velocity(t, r0, a, theta0, n, alphas[:i + 1]) for i in range(N + 1)]

        for i, (position, alpha) in enumerate(zip(positions, alphas)):
            x, y, theta = position
            print(f"Time: {t}, Joint: {i + 1}, Position: x = {x}, y = {y}, theta = {theta}, Alpha: {alpha}, Velocity: {velocities[i]}")
            data.append([t, i + 1, x, y, theta, alpha, velocities[i]])
    except ValueError as e:
        print(f"Time: {t}, Error: {e}")
# 将数据转换为DataFrame
df = pd.DataFrame(data, columns=['Time', 'Joint', 'Position_x', 'Position_y', 'Theta', 'Alpha', 'Velocity'])

# 将DataFrame保存为Excel文件
df.to_excel('result.xlsx', index=False)