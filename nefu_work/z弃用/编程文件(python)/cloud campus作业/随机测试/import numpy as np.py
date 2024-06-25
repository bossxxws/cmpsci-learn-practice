import numpy as np
import matplotlib.pyplot as plt

x=np.linspace(-3,3,100)

y1=2*x+1
y2=2*x*x+1
plt.figure(num=1)
plt.plot(x,y1,label="line")
plt.plot(x,y2,linestyle="--",label="lines")
plt.xlim((-6,8))
plt.ylim((-5,25))
plt.xlabel("xxxx")
plt.ylabel("yyyyyyyy")
plt.legend()
plt.show()
