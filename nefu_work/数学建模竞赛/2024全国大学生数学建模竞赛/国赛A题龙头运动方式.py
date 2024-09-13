import numpy as np

# 已知的参数
r0 = 8.8  # r0 > 0
a = 0.55  # a > 0
times = range(0, 301)  # 时间数据列表，取整数
n = 100  # 子区间数目，建议使用偶数
theta0 = -10  # 初始猜测值

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
def calculate_position(t, r0, a):
    theta = newton_method(t, r0, a, theta0, n)
    r_val = r_theta(theta, r0, a)
    x = r_val * np.cos(theta)
    y = r_val * np.sin(theta)
    return x, y, theta

# 对每个时间值计算对应的 x, y 和 theta
for t in times:
    try:
        x, y, theta = calculate_position(t, r0, a)
        print(f"Time: {t}, Position: x = {x}, y = {y}, theta = {theta}")
    except ValueError as e:
        print(f"Time: {t}, Error: {e}")