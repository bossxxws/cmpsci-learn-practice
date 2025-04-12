import os
import sys

from collections import deque
import collections
print(dir(deque))
print(dir(collections))
print(help(deque.popleft))
##def dfs(n):
##    if n==1:
##        return 1
##    else:
##        return n*dfs(n-1)
##
##print(dfs(5))

import math
##from collections import deque
##
##print(dir(deque))


# 首先定义一个类，要有__init__
class SN:
    def __init__(self):
        self.data = ""
        self.datalen = ""
        self.datatype = ""

### 开始初始化结构体
##a = SN()
##a.data = "233333"
##a.datalen = len(a.data)
##a.datatype = type(a.data)
##
##print(
##    f"a.data: {a.data}\n"
##    f"a.datalen: {a.datalen}\n"
##    f"a.datatype: {a.datatype}\n"
##)

import datetime

# 用2020年python省赛的题举例
start_day=datetime.date(2000,1,1) # 开始日期是2000年1月1日
end_day=datetime.date(2020,10,1) # 结束日期是2020年10月1日
td=datetime.timedelta(1) # 每次加减1天

res=0 # 记录最终的跑步距离
while(start_day<=end_day):
  if(start_day.day==1 or start_day.weekday()==0): # 是某月第一天或者是星期一
    res+=2
  else:
      res+=1
  start_day+=td # 日期往后推一天

print(res) # 答案是8879

import bisect

arr = [1, 3, 4, 4, 6, 7]

# 查找插入位置（左侧）
pos_left = bisect.bisect_left(arr, 4)  # 2
# 查找插入位置（右侧）
pos_right = bisect.bisect_right(arr, 4)  # 4
print(pos_left)
from operator import attrgetter
class Student:
    def __init__(self,sid,name):
        self.id=sid
        self.name=name

students = [Student("3005","王五"), Student("1002","张三")]
students.sort(key=attrgetter("id"))  # 输出顺序：1002 → 3005

for i in range(0,len(students)):
    print(students[i].id)





