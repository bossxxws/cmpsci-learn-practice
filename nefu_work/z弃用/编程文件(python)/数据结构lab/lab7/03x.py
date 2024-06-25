def find_scc(adj_lists):
    def dfs(graph, node, visited, stack):
        visited[node] = True
        for neighbor in graph[node]:
            if not visited[neighbor]:
                dfs(graph, neighbor, visited, stack)
        stack.append(node)

    def dfs_second(graph, node, visited, component_id, component_map):
        visited[node] = True
        component_map[node] = component_id
        for neighbor in graph[node]:
            if not visited[neighbor]:
                dfs_second(graph, neighbor, visited, component_id, component_map)

    #创建转置图
    n = len(adj_lists)
    transpose_graph = [[] for _ in range(n)]
    for u in range(n):
        for v in adj_lists[u]:
            transpose_graph[v].append(u)

    # 转置图上DFS
    visited = [False] * n
    stack = []
    for u in range(n):
        if not visited[u]:
            dfs(transpose_graph, u, visited, stack)#经过DFS栈中栈顶就是最大完成时间的NODE
    #print(stack)
    #原图上根据最大完成时间DFS
    visited = [False] * n
    component_map = {}

    while stack:
        node = stack.pop()
        if not visited[node]:
            dfs_second(adj_lists, node, visited, node, component_map)


    # 输出
    result = [component_map[node] for node in range(n)]
    print(result)

# find_scc([[1],[2],[0],[4],[5],[0,6],[2,4],[5,3]])

# [0, 0, 0, 3, 6, 6, 6, 7]