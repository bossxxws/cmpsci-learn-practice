import numpy as np
from scipy.integrate import odeint
from scipy.optimize import fsolve
import pandas as pd
import cv2

# 初始化参数

times = np.arange(0, 301, 0.5)  # 时间列表，单位：秒
L_prime = 2.86  # 第一节与龙头相连的距离
L = 1.65  # 其他节点之间的距离
N = 223  # 节点数
v0 = 1.0  # 龙头的线速度，单位：m/s

#每个木板上节点到边的参数
are=0.15
bre=0.275
cre=np.sqrt(are**2+bre**2)

# dfx = pd.DataFrame()
# dff = pd.DataFrame()
# dfv = pd.DataFrame()

time_columns = [f'{i}s' for i in range(0, 301)]
dfx = pd.DataFrame(columns=time_columns)
dfy = pd.DataFrame(columns=time_columns)

# # 创建一个空的字典，键值从0到300
# xdata = {i: [] for i in range(301)}
# ydata={i: [] for i in range(301)}
# vdata={i: [] for i in range(301)}
# data=[]

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

def calculate_rectangle_vertices(hole1, hole2, vertex):
    x1, y1 = hole1
    x2, y2 = hole2
    x3, y3 = vertex

    # 计算小孔1和2相对于已知顶点的位置向量
    hole_vector1 = np.array([x1 - x3, y1 - y3])
    hole_vector2 = np.array([x2 - x3, y2 - y3])

    # 选择离已知顶点最近的孔
    hole_distance1 = np.linalg.norm(hole_vector1)
    hole_distance2 = np.linalg.norm(hole_vector2)

    if hole_distance1 < hole_distance2:
        parent_hole = hole1
        child_hole = hole2
    else:
        parent_hole = hole2
        child_hole = hole1

    x1, y1 = parent_hole
    x2, y2 = child_hole

    # 计算两个小孔连线的方向向量
    direction_vector = np.array([x2 - x1, y2 - y1])
    direction_vector = direction_vector / np.linalg.norm(direction_vector)  # 归一化，确保是单位向量

    # 计算垂直方向向量
    perpendicular_vector1 = np.array([-direction_vector[1], direction_vector[0]])
    perpendicular_vector2 = np.array([direction_vector[1], -direction_vector[0]])

    # 计算起始顶点到父小孔的单位向量
    start_to_parent = (hole_vector1 / np.linalg.norm(hole_vector1)) if hole_distance1 < hole_distance2 else (hole_vector2 / np.linalg.norm(hole_vector2))

    # 选择正确的垂直向量
    dot_product1 = np.dot(perpendicular_vector1, start_to_parent)
    dot_product2 = np.dot(perpendicular_vector2, start_to_parent)
    perpendicular_vector = perpendicular_vector1 if dot_product1 > dot_product2 else perpendicular_vector2

    # 长方形的长和宽
    length = 2.2
    width = 0.3

    # 计算另外三个顶点
    vertex2 = np.array([x3, y3]) + length * direction_vector
    vertex3 = np.array([x3, y3]) + width * perpendicular_vector
    vertex4 = vertex2 + width * perpendicular_vector

    return (x3, y3), tuple(vertex2), tuple(vertex3), tuple(vertex4)


def genarate_P(x_0,y_0,x_1,y_1):
    if x_0==x_1:#竖直状态
        if y_0>0:
            return (x_0-are,y_0+bre)
        else:
            return (x_0+are,y_0-bre)
    elif y_0==y_1:#斜率为0状态
        if x_0<0:
            return (x_0-bre,y_0-are)
        else:
            return (x_0+bre,y_0+are)
    else:#正常情况
        k=(y_0-y_1)/(x_0-x_1)      #斜率
        print(k)
        fai=np.arctan(k)
        print(fai)
        mu=np.arctan(are/bre)
        print(mu)
        #斜率为正
        if k>0 and x_0>x_1:
            if fai+mu>np.pi/2:
                des_angle=fai+mu-np.pi/2
                return (x_0-cre*np.sin(des_angle),y_0+cre*np.cos(des_angle))
            else:
                des_angle=np.pi/2-fai-mu
                return (x_0+cre*np.sin(des_angle),y_0+cre*np.cos(des_angle))
            
        elif k>0 and x_0<x_1:
            if fai+mu<np.pi/2:
                des_angle=np.pi/2-fai-mu
                return (x_0-cre*np.sin(des_angle),y_0-cre*np.cos(des_angle))
            else:
                des_angle=fai+mu-np.pi
                return (x_0+cre*np.sin(des_angle),y_0-cre*np.cos(des_angle))
        #斜率为负
        elif k<0 and x_0<x_1:
            fai__sup=np.pi-fai#fai的补角cccccc
            if mu>fai__sup:
                des_angle=mu-fai__sup
                return (x_0-cre*np.cos(des_angle),y_0-cre*np.sin(des_angle))
            else:
                des_angle=fai__sup-mu
                return (x_0-cre*np.cos(des_angle),y_0+cre*np.sin(des_angle))
            
        else:
            fai__sup=np.pi-fai
            if fai__sup<mu:
                des_angle=mu-fai__sup
                return (x_0+cre*np.cos(des_angle),y_0+cre*np.sin(des_angle))
            else:
                des_angle=fai__sup-mu
                return (x_0+cre*np.cos(des_angle),y_0+cre*np.sin(des_angle))
            
def genarate_P2(x_0,y_0,x_1,y_1):
    if x_0==x_1:#竖直状态
        if y_0>0:
            return (x_0-are,y_0+bre)
        else:
            return (x_0+are,y_0-bre)
    elif y_0==y_1:#斜率为0状态
        if x_0<0:
            return (x_0-bre,y_0-are)
        else:
            return (x_0+bre,y_0+are)
    else:#正常情况
        k=(y_0-y_1)/(x_0-x_1)      #斜率
        print(k)
        fai=np.arctan(k)
        print(fai)
        mu=np.arctan(are/bre)
        print(mu)
        #斜率为正
        if k>0 and x_0>x_1:
            if fai+mu>np.pi/2:
                des_angle=fai+mu-np.pi/2
                return (x_0-cre*np.sin(des_angle),y_0+cre*np.cos(des_angle))
            else:
                des_angle=np.pi/2-fai-mu
                return (x_0+cre*np.sin(des_angle),y_0+cre*np.cos(des_angle))
            
        elif k>0 and x_0<x_1:
            if fai+mu<np.pi/2:
                des_angle=np.pi/2-fai-mu
                return (x_0-cre*np.sin(des_angle),y_0-cre*np.cos(des_angle))
            else:
                des_angle=fai+mu-np.pi
                return (x_0+cre*np.sin(des_angle),y_0-cre*np.cos(des_angle))
        #斜率为负
        elif k<0 and x_0<x_1:
            fai__sup=np.pi-fai#fai的补角cccccc
            if mu>fai__sup:
                des_angle=mu-fai__sup
                return (x_0-cre*np.cos(des_angle),y_0-cre*np.sin(des_angle))
            else:
                des_angle=fai__sup-mu
                return (x_0-cre*np.cos(des_angle),y_0+cre*np.sin(des_angle))
            
        else:
            fai__sup=np.pi-fai
            if fai__sup<mu:
                des_angle=mu-fai__sup
                return (x_0+cre*np.cos(des_angle),y_0+cre*np.sin(des_angle))
            else:
                des_angle=fai__sup-mu
                return (x_0+cre*np.cos(des_angle),y_0+cre*np.sin(des_angle))

# 主程序
def main1(a,r0,xdata,ydata):

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
            xdata = {i: [] for i in range(1000)}
            ydata = {i: [] for i in range(1000)}
            for i, (position, velocity) in enumerate(zip(positions, velocities)):
                x, y = position
                #print(f"Time: {t:.6f}, Node: {i}, Position: x = {x:.6f}, y = {y:.6f}, Velocity: {velocity:.6f}")
                x=format(x,'.6f')
                y=format(y,'.6f')
                v=format(velocity,'.6f')
                # 初始化数据存储结构

                xdata[i].append(x)
                ydata[i].append(y)

            # 将 xdata 的内容追加到 dfx 中
            dfx = dfx.append(xdata, ignore_index=False)
            # 将 ydata 的内容追加到 dff 中
            dff = dff.append(ydata, ignore_index=False)    
        except ValueError as e:
            print(f"Time: {t}, Error: {e}")




#判断点是否在多边形内
def point_in_rectangle(rectangle, point):
    result = cv2.pointPolygonTest(rectangle,(point[0],point[1]) ,False)
    return result > 0

#实例
# # 创建一个矩形 
# rectangle = np.array([(100, 100), (300, 100), (300, 200), (100, 200)])

# # 创建一个点
# point = (200, 150)

# # 判断点是否在矩形内
# is_inside = point_in_rectangle(rectangle, point)

# if is_inside:
#     print("点在矩形内")
# else:
#     print("点不在矩形内")

#得出一个矩形的四个点
def calculate_rectangle_vertices(hole1, hole2, vertex):
    x1, y1 = hole1
    x2, y2 = hole2
    x3, y3 = vertex

    # 计算小孔1和2相对于已知顶点的位置向量
    hole_vector1 = np.array([x1 - x3, y1 - y3])
    hole_vector2 = np.array([x2 - x3, y2 - y3])

    # 选择离已知顶点最近的孔
    hole_distance1 = np.linalg.norm(hole_vector1)
    hole_distance2 = np.linalg.norm(hole_vector2)

    if hole_distance1 < hole_distance2:
        parent_hole = hole1
        child_hole = hole2
    else:
        parent_hole = hole2
        child_hole = hole1

    x1, y1 = parent_hole
    x2, y2 = child_hole

    # 计算两个小孔连线的方向向量
    direction_vector = np.array([x2 - x1, y2 - y1])
    direction_vector = direction_vector / np.linalg.norm(direction_vector)  # 归一化，确保是单位向量

    # 计算垂直方向向量
    perpendicular_vector1 = np.array([-direction_vector[1], direction_vector[0]])
    perpendicular_vector2 = np.array([direction_vector[1], -direction_vector[0]])

    # 计算起始顶点到父小孔的单位向量
    start_to_parent = (hole_vector1 / np.linalg.norm(hole_vector1)) if hole_distance1 < hole_distance2 else (hole_vector2 / np.linalg.norm(hole_vector2))

    # 选择正确的垂直向量
    dot_product1 = np.dot(perpendicular_vector1, start_to_parent)
    dot_product2 = np.dot(perpendicular_vector2, start_to_parent)
    perpendicular_vector = perpendicular_vector1 if dot_product1 > dot_product2 else perpendicular_vector2

    # 长方形的长和宽
    length = 2.2
    width = 0.3

    # 计算另外三个顶点
    vertex2 = np.array([x3, y3]) + length * direction_vector
    vertex3 = np.array([x3, y3]) + width * perpendicular_vector
    vertex4 = vertex2 + width * perpendicular_vector

    return (x3, y3), tuple(vertex2), tuple(vertex3), tuple(vertex4)

possible_result=[]

def enumprial(m, n):

    # 每次设置a为k
    for k in np.arange(m, n, 0.01):
        a = k
        r0 = a * 16  # 新的螺线参数


        
        main1(a, r0,dfx,dfy)  
        
        # #将数据转换为列表准备保存
        # data = [list(xdata.values()), list(ydata.values()), list(vdata.values())]
        
        # #保存数据到 Excel
        # df1 = pd.DataFrame(data[0], columns=[f'{i}s' for i in range(0, 301)])  # X data
        # df2 = pd.DataFrame(data[1], columns=[f'{i}s' for i in range(0, 301)])  # Y data
        # df1.to_excel('dragon_motionx.xlsx', index=False)
        # df2.to_excel('dragon_motiony.xlsx', index=False)
        # #data[0] 存的是每秒每个节点的x坐标，data[1]存的是每秒每个节点的y坐标
        
        #枚举时间
        for t in np.arange(300,400,0.5):

            t=t*2
            t=int(t)
        #取出龙头的坐标
            print(dfx)
            print(dfy)
            lhx=dfx[t][0]
            lhy=dfy[t][0]

            poslh=genarate_P(lhx,lhy)
            #枚举龙身
            for i in range(198,225):
                #取出龙身坐标

                posbdx=dfx[t][i]
                posbdy=dfy[t][i]

                #得出龙身四个点
                verbd=calculate_rectangle_vertices(posbdx,posbdy,genarate_P2(posbdx,posbdy))
                gra=np.array([verbd[0],verbd[1],verbd[2],verbd[3]],dtype=np.float32)

                isinside=point_in_rectangle(gra,poslh)

                if(isinside):
                    possible_result.append(t)
                    return

# 枚举a的区间，这时候已经存好数据
enumprial(0.53, 0.54)
print(min(possible_result))





        
