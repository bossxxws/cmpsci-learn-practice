def dfs(adj_matrix):

    if not any(adj_matrix):
        return [],[],[],[]
    
    n = len(adj_matrix)
    visited = [False] * n
    parent = [[]*n]*n  
    tree = []
    forward = []
    back = []
    cross = []

    def dfs_visit(u):
        tree, forward, back, cross
        visited[u] = True

        for v in range(n):
            if adj_matrix[u][v] == 1:  #  u to v
                if not visited[v]:
                    # tree arc
                    tree.append((u, v))
                    parent[v].append(u) 
                    #parent[v]+=parent[u]
                    #print(v,parent[v])
                    dfs_visit(v) 
                elif u in parent[v]:
                    forward.append((u, v))
                elif v in parent[u]:
                    back.append((u, v))
                else:
                    cross.append((u, v))
                    

    #from node 0
    dfs_visit(0)

    # Sort
    tree.sort()
    forward.sort()
    back.sort()
    cross.sort()

    return tree, forward, back, cross

# a=[1,2,3]
# b=[4,5]
# b+=a
# print(b)

# adj_matrix = [[0,1,1,1],[0,0,0,1],[0,0,0,1],[0,0,0,0]]
# #adj_matrix=[[]]
# tree, forward, back, cross = dfs(adj_matrix)
# print('Tree arcs: {}'.format(tree))
# print('Forward arcs: {}'.format(forward))
# print('Back arcs: {}'.format(back))
# print('Cross arcs: {}'.format(cross))
