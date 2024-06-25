from collections import deque

def find_girth(adj_list):
    girth = float('inf')
    for start_node in range(len(adj_list)):

        dist = [-1] * len(adj_list)
        dist[start_node] = 0
    
        queue = deque([(start_node, -1)])
        while queue:
            node, parent = queue.popleft()
            for neighbor in adj_list[node]:
                if dist[neighbor] == -1:  
                    dist[neighbor] = dist[node] + 1
                    queue.append((neighbor, node))
                elif neighbor != parent:  
                    girth = min(girth, dist[node] + dist[neighbor] + 1)
    if girth == float('inf'):
        return 'inf'
    else:
        return girth
