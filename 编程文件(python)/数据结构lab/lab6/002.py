import copy

def is_reachable(adj_matrix, s, d):
    n = len(adj_matrix)
    visited = [False] * n

    q=[[]*100]*100
    tt=-1
    hh=0
    
    tt+=1#++tt
    q[tt]=[s]

    visited[s] = True

    while hh<=tt:
        #print(queue)

        path=q[hh]
        hh+=1

        current = path[-1]
        #print(path)
        if current == d:
            return True

        for neighbor in range(n):
            if adj_matrix[current][neighbor] == 1 and not visited[neighbor]:
                visited[neighbor] = True

                t=copy.copy(path)

                t.append(neighbor)
    
                tt+=1
                q[tt]=t

    return False
	
adj_matrix = [
    [0, 0, 1, 0, 1, 1],
    [1, 0, 0, 0, 0, 0],
    [0, 1, 0, 0, 1, 0],
    [1, 0, 0, 0, 1, 0],
    [0, 0, 0, 0, 0, 0],
    [1, 0, 0, 0, 0, 0]
]
print(is_reachable(adj_matrix, 0, 3))
print(is_reachable(adj_matrix, 1, 2))