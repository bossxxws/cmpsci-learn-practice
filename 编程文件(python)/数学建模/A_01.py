import matplotlib.pyplot as plt
import numpy as np

plt.rc('font', family='KaiTi', weight='bold')

#定义一维数组
t = np.arange(0, 5, 0.2)

#使用数组同时绘制多个线性

#线条1
x1=y1=t
#线条2
x2=x1
y2=t**2
#线条3
x3=x1
y3=t**3
#使用plot绘制线条
linesList=plt.plot(
        x1, y1,  
        x2, y2,  
        x3, y3)
#用setp方法可以同时设置多个线条的属性
plt.setp(linesList, color='r')
plt.show()
print('返回的数据类型',type(linesList))
print('数据大小：',len(linesList))

x=[]
y=[]

for i in range(1,1001):
    x.append(i)
    y.append(i*i)

plt.plot(x,y,color="y",marker="o",linestyle="dashed")

plt.xlabel("n")
plt.ylabel("n的平方")

plt.axis([0,1000,0,1000*1000])

plt.show()

#创建画板1
fig = plt.figure(1) #如果不传入参数默认画板1
#第2步创建画纸，并选择画纸1
ax1=plt.subplot(2,1,1)   
#在画纸1上绘图
plt.plot([1, 2, 3])
#选择画纸2
ax2=plt.subplot(2,1,2)
#在画纸2上绘图
plt.plot([4, 5, 6])
#显示图像
plt.show()

def dfs(graphr,graphv,curlen,N,dis,node,res,st):
    if(curlen==N):
        res=min(res,dis)
        return res
    for i in graphr[node]:
        if(st[node][i]==False):
           st[node][i]=True
           res=min(dfs(graphr,graphv,curlen+graphr[node][i],N,dis+graphr[node][i]+graphv[node][i],i,res,st),res)
           st[node][i]=False
    return res


graphr=[[0 for _ in range(5)]for _ in range(3)]#存放实线

graphv=[[0 for _ in range(5)]for _ in range(3)]#存放空程

st=[[False for _ in range(5)]for _ in range(3)]#创建3*5的false矩阵

res=1e9

print(dfs(graphr,graphv,0,0,0,0,res,st))