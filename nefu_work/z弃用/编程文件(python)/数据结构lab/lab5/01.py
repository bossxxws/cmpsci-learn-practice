class Graph:
    def __init__(self, adj_list):
        self.data = adj_list
        
    def __init__(self, adj_matrix):#adj是需要转换的邻接矩阵
        # write your codes to convert an adjacency matrix to an adjacency list
        
        self.edge=0;
        
        self.data={}
        for i in range (len(adj_matrix)):
            self.data[i]=[]
            for j in range(len(adj_matrix)):
                if adj_matrix[i][j]==1:
                    self.data[i].append(j)
                    self.edge+=1

    def size(self):
        # write your codes here
        return self.edge
        
    def order(self):
        # write your codes here
        return len(self.data)
    
    def add_node(self, node):
        # write your codes here
        if node not in self.data:
            self.data[node] = []

    def remove_node(self, node):
        # write your codes here
        if node in self.data:
            del self.data[node]
            for n in self.data:
                if node in self.data[n]:
                    self.data[n].remove(node)
        
    def add_arc(self, source_node, target_node):
        # write your codes here
        if source_node not in self.data:
            self.data[source_node] = []
        if target_node not in self.data:
            self.data[target_node] = []
        if target_node not in self.data[source_node]:
            self.data[source_node].append(target_node)
            self.data[source_node].sort();
            
    def remove_arc(self, source_node, target_node):
        # write your codes here.
         if source_node in self.data and target_node in self.data[source_node]:
            self.data[source_node].remove(target_node)