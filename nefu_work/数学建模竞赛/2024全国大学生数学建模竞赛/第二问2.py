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
            if fai+mu<np.pi/2:
                des_angle=np.pi/2-fai-mu
                return (x_0-c*np.sin(des_angle),y_0-c*np.cos(des_angle))
            else:
                des_angle=fai+mu-np.pi
                return (x_0+c*np.sin(des_angle),y_0-c*np.cos(des_angle))
        #斜率为负
        elif k<0 and x_0<x_1:
            fai__sup=np.pi-fai#fai的补角cccccc
            if mu>fai__sup:
                des_angle=mu-fai__sup
                return (x_0-c*np.cos(des_angle),y_0-c*np.sin(des_angle))
            else:
                des_angle=fai__sup-mu
                return (x_0-c*np.cos(des_angle),y_0+c*np.sin(des_angle))
            
        else:
            fai__sup=np.pi-fai
            if fai__sup<mu:
                des_angle=mu-fai__sup
                return (x_0+c*np.cos(des_angle),y_0+c*np.sin(des_angle))
            else:
                des_angle=fai__sup-mu
                return (x_0+c*np.cos(des_angle,y_0+c*np.sin(des_angle)))
    

    # x_theo,y_theo=intersection
    # print(x_theo,y_theo)
    # dist=np.sqrt((x_theo-x_0)**2+(y_theo-y_0)**2)
    # aaa+=[dist]
    # # print(dist)
    # # print(c**2)
    # return dist<=c

def generate_line(i,t):
    A=y_i_1-y_i
    B=x_i-x_i_1
    C=x_i_1*y_i-x_i*y_i_1
    return A,B,C

def cal_dist(A,B,C):
    dist=abs((A*p_x+B*p_y+C)/np.sqrt(A**2+B**2))
    return dist
def compare():
    return dist<=a

a=0.15
b=0.275
c=np.sqrt(a**2+b**2)
aaa=[]

file_path="result.xlsx"
df=pd.read_excel(file_path)
v0_addresses=df[df['Joint']==0]
# print(v0_addresses)
# print(000000)
v1_addresses=df[df['Joint']==1]

possible=np.arange(400,450,0.5)

possible_result=[]

for i in range(1,25):
    vi_addresses=df[df['Joint']==i]
    vi_1_addresses=df[df['Joint']==i+1]
    # print(vi_1_addresses)
    print(i)
    for t in possible:
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
        # print(p_x,p_y)
        A,B,C=generate_line(i,t)
        dist=cal_dist(A,B,C)

        if compare():possible_result+=[t]
        print(i,i,i)

print(min(possible_result))