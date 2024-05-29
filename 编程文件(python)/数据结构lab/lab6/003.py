from collections import deque

def distance(adj_list, s):
    n = len(adj_list)
    distances = [float('inf')] * n
    distances[s] = 0
    queue = deque([s])

    while queue:
        u = queue.pop()
        for v in adj_list[u]:
            if distances[v] == float('inf'):
                distances[v] = distances[u] + 1
                queue.append(v)

    return distances
