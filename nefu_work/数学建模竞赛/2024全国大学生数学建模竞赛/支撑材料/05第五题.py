import numpy as np
from scipy.integrate import odeint
from scipy.optimize import fsolve
import pandas as pd
# 初始化参数
r0 = 8.8  # 螺旋线的初始半径
a = 0.55  # 螺距
times = np.arange(0, 301, 1)  # 时间列表，单位：秒
L_prime = 2.86  # 第一节与龙头相连的距离
L = 1.65  # 其他节点之间的距离
N = 223  # 节点数
v0 = 1.0 # 龙头的线速度，单位：m/s
# 创建一个空的字典，键值从0到300
xdata = {i: [] for i in range(301)}
ydata={i: [] for i in range(301)}
vdata={i: [] for i in range(301)}
#输出位置的函数
def posprint(t,pjoint,dic):
    print(f"第{t}秒：第{pjoint}节位置:{dic[pjoint][t]}")
    print("\n")
#输出速度的函数
def vprint(t,pjoint,dic):
    print(f"第{t}秒：第{pjoint}节速度:{dic[pjoint][t]}")
    print("\n")
# 定义螺旋方程，给定角度 \theta 计算半径 r
def r_theta(theta, r0, a):
    return r0 + a / (2 * np.pi) * theta
# 定义微分方程，给定 \theta 求解角速度 d\theta/dt
def diff_eq(theta, t, r0, a):
    return -1 / np.sqrt((r0 - (a / (2 * np.pi)) * theta)**2 + (a / (2 * np.pi))**2)
# 求解龙头的 \theta_0(t)
def solve_theta0(r0, a, theta0_initial, times):
    theta0_solutions = odeint(diff_eq, theta0_initial, times, args=(r0, a))
    return theta0_solutions.flatten()
# 计算每个节点的角度增量 \(\alpha\)
def solve_alpha(theta, L, r0, a):
    def func(alpha):
        r_theta_alpha = r_theta(theta + alpha, r0, a)
        r_theta_val = r_theta(theta, r0, a)
        return (r_theta_alpha ** 2 + r_theta_val ** 2 - L ** 2) / (2 * r_theta_alpha * r_theta_val) - np.cos(alpha)
    alpha_guess = np.pi / 2  # 初始猜测角度
    alpha_solution, = fsolve(func, alpha_guess)
    return alpha_solution
# 计算每个节点的线速度
def calculate_velocity(theta, r0, a, angular_velocity):
    r_val = r_theta(theta, r0, a)
    return r_val * angular_velocity
# 主程序
def main():
    # 初始化数据存储
    data = []
    # 计算龙头在各个时间点的角度 \theta_0(t)
    theta0_initial = 0  # 初始角度
    theta0_solutions = solve_theta0(r0, a, theta0_initial, times)
    # 计算龙头的初始角速度 \omega_0
    r0_theta0 = r_theta(theta0_solutions[0], r0, a)
    omega0 = v0 / r0_theta0  # 角速度：\omega_0 = v_0 / r_0
    # 主循环：遍历每一个时间点
    for t_idx, t in enumerate(times):
        try:
            # 存储每个时间点的所有节点信息
            thetas = []
            positions = []
            velocities = []
            # 计算龙头的角位置、线速度、位置
            theta0 = theta0_solutions[t_idx]  # 龙头的角度
            thetas.append(theta0)  
            # 计算龙头的位置
            x0 = r_theta(theta0, r0, a) * np.cos(theta0)
            y0 = r_theta(theta0, r0, a) * np.sin(theta0)
            positions.append((x0, y0))      
            # 龙头的速度已知为 v0 = 1 m/s
            velocities.append(v0)
            # 计算龙身节点的角位置、位置和速度
            for i in range(1, N + 1):  # 遍历每个节点
                # 计算角度增量 \alpha_i
                if i == 1:
                    alpha = solve_alpha(thetas[-1], L_prime, r0, a)
                else:
                    alpha = solve_alpha(thetas[-1], L, r0, a)
                # 计算当前节点的角位置 \theta_i
                theta_i = thetas[-1] + alpha
                thetas.append(theta_i)
                # 计算当前节点的位置
                x_i = r_theta(theta_i, r0, a) * np.cos(theta_i)
                y_i = r_theta(theta_i, r0, a) * np.sin(theta_i)
                positions.append((x_i, y_i))
                # 假设节点的角速度与前一个节点相同，计算线速度
                v_i = calculate_velocity(theta_i, r0, a, omega0)
                velocities.append(v_i)
            # 输出当前时间点的每个节点信息
            for i, (position, velocity) in enumerate(zip(positions, velocities)):
                x, y = position
                # print(f"Time: {t:.6f}, Node: {i}, Position: x = {x:.6f}, y = {y:.6f}, Velocity: {velocity:.6f}")
                x=format(x,'.6f')
                y=format(y,'.6f')
                v=format(velocity)

                xdata[i].append(x)
                ydata[i].append(y)
                vdata[i].append(v)
        except ValueError as e:
            print(f"Time: {t}, Error: {e}")
right=float(2)
left=float(0)
#精度较高运行较慢，但必可得出精确结果
while(right-left>1e-8):
    mid=(right+left)/2
    v0=mid
    main()
    print(f"当前0时刻末尾速度：{vdata[223][0]}")
    #print(vdata)
    if float(vdata[223][0])>2:#如果大于2说明初始速度太大
        right=mid
    else:
        left=mid
    print(f"当前v0数值：{left}\n")
    xdata = {i: [] for i in range(301)}
    ydata={i: [] for i in range(301)}
    vdata={i: [] for i in range(301)}
print(f"最终满足条件的龙头初速度v0:{left}")

