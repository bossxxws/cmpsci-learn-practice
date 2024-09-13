import pandas as pd
import numpy as np
import cv2
a=0.15
b=0.275
c=np.sqrt(a**2+b**2)
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
#判断点是否在多边形内
def point_in_rectangle(rectangle, point):
    result = cv2.pointPolygonTest(rectangle,(point[0],point[1]) ,False)
    return result > 0
def genarate_P():
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
                return (x_0+c*np.cos(des_angle),y_0+c*np.sin(des_angle))
def genarate_P2(x_0,y_0,x_1,y_1):
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
                return (x_0+c*np.cos(des_angle),y_0+c*np.sin(des_angle))
file_path="resultrough.xlsx"
df=pd.read_excel(file_path)
v0_addresses=df[df['Joint']==0]
print(v0_addresses)
# print(v0_addresses)
# print(000000)
v1_addresses=df[df['Joint']==1]
possible=np.arange(350,450,0.5)
possible_result=[]
for i in range(1,25):
    vi_addresses=df[df['Joint']==i]
    vi_1_addresses=df[df['Joint']==i+1]
    # print(vi_1_addresses)
    print(i)
    for t in possible:
        t=np.trunc(t*10)//10
        print(v0_addresses[v0_addresses['Time']==t].to_dict('records'),t)
        v0_data=v0_addresses[v0_addresses['Time']==t].to_dict('records')[0]
        # print(v0_data)
        # print(22222)
        v1_data=v1_addresses[v1_addresses['Time']==t].to_dict('records')[0]
        #龙头
        x_0,y_0=v0_data['Position_x'],v0_data['Position_y']
        x_1,y_1=v1_data['Position_x'],v1_data['Position_y']
        # print(x_0,x_1)
        # print(333333)
        vi_data=vi_addresses[vi_addresses['Time']==t].to_dict('records')[0]
        vi_1_data=vi_1_addresses[vi_1_addresses['Time']==t].to_dict('records')[0]
        #龙身
        x_i,y_i=vi_data['Position_x'],vi_data['Position_y']#头
        # print(x_i,y_i)
        x_i_1,y_i_1=vi_1_data['Position_x'],vi_1_data['Position_y']#尾
        pos_x_y=genarate_P()
        posx1y1=genarate_P2(x_i,y_i,x_i_1,y_i_1)
        vers=np.array([calculate_rectangle_vertices((x_i,y_i),(x_i_1,y_i_1),posx1y1)[0],calculate_rectangle_vertices((x_i,y_i),(x_i_1,y_i_1),posx1y1)[1],
                      calculate_rectangle_vertices((x_i,y_i),(x_i_1,y_i_1),posx1y1)[2],calculate_rectangle_vertices((x_i,y_i),(x_i_1,y_i_1),posx1y1)[3]],
                      dtype=np.float32)
        isinseide=point_in_rectangle(vers,pos_x_y)
        if(isinseide):
            possible_result.append(t-0.2)
print(min(possible_result))




