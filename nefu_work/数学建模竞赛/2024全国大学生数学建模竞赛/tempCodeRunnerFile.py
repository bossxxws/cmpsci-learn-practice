import numpy as np
from scipy.integrate import odeint
from scipy.optimize import fsolve

# 已知的参数
r0 = 8.8  # r0 > 0
a = 0.55  # a > 0
times = np.arange(0, 301, 1)  # 时间数据列表，取整数
n = 100  # 子区间数目，建议使用偶数
theta0_initial = 0  # 初始条件 theta_0(0) = 0
L_prime = 2.86  # 第一节与龙头相连的直线长度
L = 1.65  # 其余节数的直线长度
N = 222  # 节数量

# # 定义被积函数
# def f(x, r0, a):
#     return np.sqrt((r0 + (a / (2 * np.pi)) * x)**2 + (a / (2 * np.pi))**2)

# 定义微分方程
def diff_eq(theta, t, r0, a):
    return -1 / np.sqrt((r0 - (a / (2 * np.pi)) * theta)**2 + (a / (2 * np.pi))**2)

# 解微分方程得到 theta0(t)
def solve_diff_eq(r0, a, theta0_initial, times):
    theta0_solutions = odeint(diff_eq, theta0_initial, times, args=(r0, a))
    return theta0_solutions

# 螺线方程
def r_theta(theta, r0, a):
    return r0 + a / (2 * np.pi) * theta

# 计算位置
def calculate_position(theta, r0, a):
    r_val = r_theta(theta, r0, a)
    x = r_val * np.cos(theta)
    y = r_val * np.sin(theta)
    return x, y, theta

# 使用牛顿法求解alpha值
def newton_method(theta, r0, a, L, tol):
    alpha = theta
    for _ in range(n):
        r_theta_alpha = r_theta(theta + alpha, r0, a)
        r_theta_val = r_theta(theta, r0, a)
        f_alpha = (r_theta_alpha ** 2 + r_theta_val ** 2 - L ** 2) / (2 * r_theta_alpha * r_theta_val) - np.cos(alpha)
        df_alpha = -1 - np.sin(alpha) + (r_theta_alpha * np.sin(alpha) - r_theta_val * np.cos(alpha)) / (r_theta_alpha ** 2)
        alpha = alpha - f_alpha / df_alpha
    return alpha

def dalpha_dt(t, r0, a, theta0, n, L, i, tol=1e-10):
    h = tol  # 使用一个很小的步长来近似导数

    # 计算 t+h 时刻的 theta0
    theta0_plus = odeint(diff_eq, theta0, [t + h], args=(r0, a))[0]
    # 计算 t-h 时刻的 theta0
    theta0_minus = odeint(diff_eq, theta0, [t - h], args=(r0, a))[0]

    # 使用 t+h 和 t-h 时刻的 theta0 计算 alpha
    alpha_plus = newton_method(theta0_plus, r0, a, L, tol)
    alpha_minus = newton_method(theta0_minus, r0, a, L, tol)

    # 使用中心差分法近似计算导数
    dalpha_dt_approx = (alpha_plus - alpha_minus) / (2 * h)
    return dalpha_dt_approx


# 计算速度
def calculate_velocity(dtheta_dt_0,sum,  r0, a):
    dr_dtheta = a / (2 * np.pi)
    r_val = r_theta(theta, r0, a)
    dx_dtheta = dr_dtheta * np.cos(theta) - r_val * np.sin(theta)
    dy_dtheta = dr_dtheta * np.sin(theta) + r_val * np.cos(theta)

    velocity = np.sqrt((dx_dtheta * (dtheta_dt_0+sum)) ** 2 + (dy_dtheta * (dtheta_dt_0+sum)) ** 2)
    return velocity


# 解微分方程得到 theta0(t) 的值
theta0_solutions = solve_diff_eq(r0, a, theta0_initial, times)

# 主循环
for t_idx, t in enumerate(times):
    try:
        thetas = []
        alphas = []
        positions = []
        velocities = []
        dalpha_dt_sums = []
        theta0 = theta0_solutions[t_idx][0]  # 从数组中提取具体值
        dtheta_dt_0 = diff_eq(theta0, t, r0, a)  # 直接使用微分方程求导数
        thetas.append(theta0)
        x, y, theta_val = calculate_position(theta0, r0, a)
        positions.append((x, y, theta_val))
        dalpha_dt_sums.append(0)  # 对于第一节的alpha，其导数为0

        for i in range(1, N + 1):
            if i == 1:
                L_current = L_prime
            else:
                L_current = L

            # 计算 alpha 和其关于时间的导数
            alpha = newton_method(theta0, r0, a, L_current, 1e-10)
            dalpha_dt_i = dalpha_dt(t, r0, a, theta0, n, L_current, i, 1e-10)
            # print(dalpha_dt_i)
            alphas.append(alpha)
            theta = thetas[-1] + alpha
            thetas.append(theta)
            x, y, theta_val = calculate_position(theta, r0, a)
            positions.append((x, y, theta_val))
            dalpha_dt_sums.append(dalpha_dt_i)

        for i, (position, alpha) in enumerate(zip(positions, alphas)):
            x, y, theta = position
            # 计算速度时，考虑所有之前的alpha的导数和
            sum=0
            for k in range(len(dalpha_dt_sums)):
                if i==0:
                    break
                else :sum+=dalpha_dt_sums[k]

            velocity = calculate_velocity(dtheta_dt_0, sum, r0, a)
            print(f"Time: {t:.6f}, Joint: {i}, Position: x = {x:.6f}, y = {y:.6f}, theta = {theta:.6f}, Alpha: {alpha:.6f}, Velocity: {velocity:.6f}")
    except ValueError as e:
        print(f"Time: {t}, Error: {e}")