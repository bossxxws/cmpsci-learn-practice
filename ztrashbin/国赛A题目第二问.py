#已知参数
#每个点的位置vi
#龙头位置v0
#碰撞点 P
import pandas as pd
import numpy as np


#生成对应时刻的P
def genarate_P(t):
    
    
    if x_0==x_1:#竖直状态
        if y_0>0:
            return (x_0-a,y_0+b)
        else:
            return (x_0+a,y_0-b)
    elif y_0==y_1:#斜率为0状态
        if x_0<0:
            return (x_0-b,y_0-a)
        else:
            return (x_0+b,y_0+a)
    else:#正常情况
        k=(y_0-y_1)/(x_0-x_1)      #斜率
        print(k)
        fai=np.arctan(k)
        print(fai)
        mu=np.arctan(a/b)
        print(mu)
        #斜率为正
        if k>0 and x_0>x_1:
            if fai+mu>np.pi/2:
                des_angle=fai+mu-np.pi/2
                return (x_0-c*np.sin(des_angle),y_0+c*np.cos(des_angle))
            else:
                des_angle=np.pi/2-fai-mu
                return (x_0+c*np.sin(des_angle),y_0+c*np.cos(des_angle))
            
        elif k>0 and x_0<x_1:
            des_angle=np.pi/2-fai-mu
            return (x_0-c*np.sin(des_angle),y_0-c*np.cos(des_angle))

        #斜率为负
        elif k<0 and x_0<x_1:
            fai__sup=np.pi-fai#fai的补角
            if mu>fai__sup:
                des_angle=np.pi/2-(mu-fai__sup)
                return (x_0-c*np.sin(des_angle),y_0-c*np.cos(des_angle))
            else:
                des_angle=np.pi/2-(fai__sup-mu)
                return (x_0-c*np.sin(des_angle),y_0+c*np.cos(des_angle))
            
        else:
            fai__sup=np.pi-fai
            if fai__sup<mu:
                des_angle=np.pi/2-(fai__sup-mu)
                return (x_0+c*np.sin(des_angle),y_0+c*np.cos(des_angle))
            else:
                des_angle=fai__sup-mu
                return (x_0+c*np.cos(des_angle,y_0+c*np.sin(des_angle)))
    

#生成被撞线
def generate_line(t,i):
    
    
    if x_i==x_i_1:
        if y_i<y_i_1:
            return (1,0,-x_i+a)
        else:
            return (1,0,-x_i-a)
    elif y_i==y_i_1:
        if x_i>x_i_1:
            return (0,1,-y_i+a)
        else:
            return (0,1,-y_i-a)
    
    #一般情况
    else:
        #A=k2
        #B=-1
        #C=-k2*g_x+g_y
        #G(g_x,g_y)
        k2=(y_i_1-y_i)/(x_i_1-x_i)
        fai2=np.arctan(k2)
        mu=np.arctan(a/b)
        if k2>0 and x_i>x_i_1:
            des_angle=fai2-mu
            g_x=x_i+c*np.cos(des_angle)
            g_y=y_i+c*np.sin(des_angle)
        elif k2>0 and x_i<x_i_1:
            if fai2<mu:
                des_angle=mu-fai2
                g_x=x_i-c*np.cos(des_angle)
                g_y=y_i+c*np.sin(des_angle)
            else:
                des_angle=fai2-mu
                g_x=x_i-c*np.cos(des_angle)
                g_y=y_i-c*np.sin(des_angle)
        
        elif k2<0 and x_i<x_i_1:
            fai2_sup=np.pi-fai2
            if fai2_sup+mu>np.pi/2:
                des_angle=fai2_sup+mu-np.pi/2
                g_x=x_i+c*np.sin(des_angle)
                g_y=y_i+c*np.cos(des_angle)
            else:
                des_angle=np.pi/2-fai2_sup-mu
                g_x=x_i-c*np.sin(des_angle)
                g_y=y_i+c*np.cos(des_angle)
        
        else:
            fai2_sup=np.pi-fai2
            if fai2_sup+mu>np.pi/2:
                des_angle=fai2_sup+mu-np.pi/2
                g_x=x_i-c*np.sin(des_angle)
                g_y=y_i-c*np.cos(des_angle)
            else:
                des_angle=np.pi/2-fai2_sup-mu
                g_x=x_i+c*np.sin(des_angle)
                g_y=y_i-c*np.cos(des_angle)

        A=k2
        B=-1
        C=-k2*g_x+g_y
        return (A,B,C)


#生成与被撞线相交的线
def generate_line2(x2,y2):
    A=y2-y_0
    B=x_0-x2
    C=(y_0-y2)*x_0+y_0*(x2-x_0)
    return A,B,C
    
#两线相交得到理论距离
def calculate_theoretial_dist(A1,B1,C1,A2,B2,C2):
    print(A1,B1,C1,A2,B2,C2)
    #构建增广矩阵
    coeff_matrix = np.array([[A1, B1], [A2, B2]])  # 系数矩阵
    const_vector = np.array([-C1, -C2])            # 常数项向量

# 使用numpy的linalg.solve()来解方程组
    try:
        solution = np.linalg.solve(coeff_matrix, const_vector)
        x, y = solution
        return x,y
    except np.linalg.LinAlgError:
        return None

def compare():
    x_theo,y_theo=intersection
    # print(x_theo,y_theo)
    dist=(x_theo-x_0)**2+(y_theo-y_0)**2
    # print(dist)
    # print(c**2)
    return dist<=c**2

a=0.15
b=0.275
c=np.sqrt(a**2+b**2)

file_path="result.xlsx"
df=pd.read_excel(file_path)
v0_addresses=df[df['Joint']==0]
# print(v0_addresses)
# print(000000)
v1_addresses=df[df['Joint']==1]

possible=np.arange(1,24,1)

possible_result=[]

for i in range(1,2):
    vi_addresses=df[df['Joint']==i]
    vi_1_addresses=df[df['Joint']==i+1]
    # print(vi_1_addresses)
    print(i)
    for t in range(400,401):
        v0_data=v0_addresses[v0_addresses['Time']==t].to_dict('records')[0]
        # print(v0_data)
        # print(22222)
        v1_data=v1_addresses[v1_addresses['Time']==t].to_dict('records')[0]

        x_0,y_0=v0_data['Position_x'],v0_data['Position_y']
        x_1,y_1=v1_data['Position_x'],v1_data['Position_y']

        # print(x_0,x_1)
        # print(333333)

        vi_data=vi_addresses[vi_addresses['Time']==t].to_dict('records')[0]
        vi_1_data=vi_1_addresses[vi_1_addresses['Time']==t].to_dict('records')[0]

        x_i,y_i=vi_data['Position_x'],vi_data['Position_y']
        # print(x_i,y_i)
        x_i_1,y_i_1=vi_1_data['Position_x'],vi_1_data['Position_y']
        
        p_x,p_y=genarate_P(t)
        print(p_x,p_y)
        A1,B1,C1=generate_line(t,i)
        # print(1)
        A2,B2,C2=generate_line2(p_x,p_y)
        # print(2)
        intersection=calculate_theoretial_dist(A1,B1,C1,A2,B2,C2)
        # print(4)
        if not intersection:continue#无交点
        # print(3)
        if compare():
            possible_result+=[t]
            # print("//////////////")
            break
            
        print(i,i,i)
print(min(possible_result))