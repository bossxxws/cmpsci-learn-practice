def dfs(adj_matrix):
    n = len(adj_matrix)
    visited = [False] * n
    parent = [[]*n]*n  # Track the parent of each node in the DFS tree
    tree = []
    forward = []
    back = []
    cross = []

    def dfs_visit(u):
        nonlocal tree, forward, back, cross
        visited[u] = True
        for v in range(n):
            if adj_matrix[u][v] == 1:  #  u to v
                if not visited[v]:
                    # tree arc
                    tree.append((u, v))
                    parent[v].append(u) 
                    dfs_visit(v)  # Continue DFS from v
                elif u in parent[v]:
                    forward.append((u, v))
                elif v in parent[u]:
                    back.append((u, v))
                else:
                    cross.append((u, v))
                    

    # Start DFS from node 0
    dfs_visit(0)

    # Sort the lists as required
    tree.sort()
    forward.sort()
    back.sort()
    cross.sort()

    return tree, forward, back, cross

'''
adj_matrix = [[0,1,1,1],[0,0,0,1],[0,0,0,1],[0,0,0,0]]
tree, forward, back, cross = dfs(adj_matrix)
print('Tree arcs: {}'.format(tree))
print('Forward arcs: {}'.format(forward))
print('Back arcs: {}'.format(back))
print('Cross arcs: {}'.format(cross))
'''