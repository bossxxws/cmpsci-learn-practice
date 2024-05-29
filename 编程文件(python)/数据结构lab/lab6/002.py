from collections import deque

import copy

def is_reachable(adj_matrix, s, d):
    n = len(adj_matrix)
    visited = [False] * n
    queue = deque([[s]])
    visited[s] = True

    while queue:
        #print(queue)
        path = queue.pop()
        
        current = path[-1]
        #print(path)
        if current == d:
            return True

        for neighbor in range(n):
            if adj_matrix[current][neighbor] == 1 and not visited[neighbor]:
                visited[neighbor] = True

                t=copy.copy(path)

                t.append(neighbor)
    
                queue.append(t)

    return False
	
# adj_matrix = [
#     [0, 0, 1, 0, 1, 1],
#     [1, 0, 0, 0, 0, 0],
#     [0, 1, 0, 0, 1, 0],
#     [1, 0, 0, 0, 1, 0],
#     [0, 0, 0, 0, 0, 0],
#     [1, 0, 0, 0, 0, 0]
# ]
# print(is_reachable(adj_matrix, 0, 3))
# print(is_reachable(adj_matrix, 1, 2))