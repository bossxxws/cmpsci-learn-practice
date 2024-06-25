def distance(adj_list, s):
    n = len(adj_list)
    distances = [float('inf')] * n
    tt=-1
    hh=0
    q=[0]*100000
    distances[s] = 0

    tt+=1
    q[tt]=s

    while hh<=tt:
        u = q[hh]
        hh+=1
        for v in adj_list[u]:
            if distances[v] == float('inf'):
                distances[v] = distances[u] + 1
                tt+=1
                # print(tt)
                q[tt]=v

    return distances

# adj_list = [[], [2, 3], [1, 4], [1], [2]]
# d = distance(adj_list, 0)
# print(d)
# d = distance(adj_list, 2)
# print(d)