class DisjointSet:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        xr = self.find(x)
        yr = self.find(y)
        if xr != yr:
            if self.rank[xr] < self.rank[yr]:
                self.parent[xr] = yr
            elif self.rank[xr] > self.rank[yr]:
                self.parent[yr] = xr
            else:
                self.parent[yr] = xr
                self.rank[xr] += 1

def Kruskal(adj_matrix):
    n = len(adj_matrix)
    edges = []
    for i in range(n):
        for j in range(i+1, n):
            if adj_matrix[i][j] != 0:
                edges.append((i, j, adj_matrix[i][j]))
    edges.sort(key=lambda x: (x[2], x[0], x[1]))

    ds = DisjointSet(n)
    res_adj = [[0]*n for _ in range(n)]
    length = 0
    for i, j, w in edges:
        if ds.find(i) != ds.find(j):
            ds.union(i, j)
            res_adj[i][j] = w
            res_adj[j][i] = w
            length += w
    return res_adj, length
