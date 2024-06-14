'''
Let's say we have N
 modules in a software. A module may use the output of the other modules to complete some tasks. Now, you are provided by an array dep of length N
, which stores the dependency of the modules. For example, if module 0 needs the output from module 1 and 2, then dep[0]=[1,2].

Your task is to arrange a proper order for the software to successfully run all the modules one by one. Write a function schedule to return a proper order given the array dep. For example, if dep=[[],[],[0,1]]
, the proper orders could be [0, 1, 2] or [1, 0, 2], because module 2 depends on module 0 and 1. 

Note: When there are two modules that can run at the same time, choose the one with smaller node label. Use the above example, both module 0 and 1 should be run before node 2, but you should return [0, 1, 2]. If there is no proper order, return None.

For example:

Test	
dep = [[],[],[0,1]]
print(schedule(dep))

Result
[0, 1, 2]

Test
dep = [[],[],[0,1]]
print(schedule(dep))

Result
[0, 1, 2]

Test
dep = [[],[0],[0],[2,5],[1],[1],[3,4,5]]
print(schedule(dep))

Result
[0, 1, 2, 4, 5, 3, 6]

Test
dep = [[1,2],[3,5],[3],[6,7,8],[5],[6,9],[8],[8],[9],[]]
print(schedule(dep))

Result

[9, 8, 6, 5, 4, 7, 3, 1, 2, 0]

'''
from collections import deque

def schedule(dep):
    N = len(dep)
    m={}
    indegree = [0]*N
    for i in range(N):
        for j in dep[i]:
            indegree[i] += 1#记录每个点的入度
            m[j]=i 

    queue = deque([i for i in range(N) if indegree[i] == 0])
    res = []
    while queue:
        l=sorted(list(queue))
        print(l)
        queue=deque(l)
        node = queue.pop()
        res.append(node)
        for i in dep[node]:
            indegree[i] -= 1
            if indegree[i] == 0:
                queue.append(i)

    if len(res) == N:
        return list(reversed(res))
    else:
        return None


dep = [[],[0],[0],[2,5],[1],[1],[3,4,5]]
print(schedule(dep))
