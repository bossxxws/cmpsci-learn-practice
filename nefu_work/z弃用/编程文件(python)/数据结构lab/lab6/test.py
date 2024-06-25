import numpy as np
import matplotlib.pyplot as plt
from sympy import *

# 定义要绘制的函数
def f(x):
    return x**2 + 2*x + 1

# 创建x轴数据
x = np.linspace(-5, 5)

# 计算函数值
y = f(x)

# 绘制函数图
plt.figure(figsize=(8, 6))
plt.plot(x, y)
plt.title('函数图')
plt.xlabel('x')
plt.ylabel('f(x)')
plt.grid(True)
plt.show()
