'''
We have learned how to find the strong components for a directed graph in the class. Now, you are asked to implement the algorithm we discussed in the class. Given the adjacency lists of a di-graph, your function should print the affiliation of each node to the root of traversal tree it belongs to. 

For example, given the adjacency lists of the example below as [[3],[0],[0,3,4],[1],[2]]. We get two traversal trees after the second run of DFS: T1 = {(0,3), (3,1)}, T2 = {(2,4)}. Then, the nodes 0,1,3 all belong the tree rooted at node 0, and nodes 2, 4 belong to the tree rooted at node 2. You need to print an array [0, 0, 2, 0, 2]. You can use any python built-in package to complete this exercise.



For example:

Test	
find_scc([[3],[0],[0,3,4],[1],[2]])

Result
[0, 0, 2, 0, 2]


find_scc([[1],[2],[0],[4],[5],[0,6],[2,4],[5,3]])

[0, 0, 0, 3, 6, 6, 6, 7]
'''
def find_scc(adj_lists):
    def dfs(v, adj, visited, stack):
        visited[v] = True
        for u in adj[v]:
            if not visited[u]:
                dfs(u, adj, visited, stack)
        stack.append(v)

    def reverse_graph(adj):
        r_adj = [[] for _ in range(len(adj))]
        for v in range(len(adj)):
            for u in adj[v]:
                r_adj[u].append(v)
        return r_adj

    def assign_scc(v, root, adj, visited, scc):
        visited[v] = True
        scc[v] = root
        for u in adj[v]:
            if not visited[u]:
                assign_scc(u, root, adj, visited, scc)

    visited = [False]*len(adj_lists)
    stack = []
    for v in range(len(adj_lists)):
        if not visited[v]:
            dfs(v, adj_lists, visited, stack)

    r_adj_lists = reverse_graph(adj_lists)

    visited = [False]*len(adj_lists)
    scc = [-1]*len(adj_lists)
    while stack:
        v = stack.pop()
        if not visited[v]:
            assign_scc(v, v, r_adj_lists, visited, scc)

    print(scc)
find_scc([[1],[2],[],[4],[5],[0,6],[2,4],[5,3]])

