def dfs_cal(adj_matrix, tree, forward, back, cross, vertex, number, color, pred):
    color[vertex] = "Grey"
    for i in range(number):
        if adj_matrix[vertex][i] == 1:
            if color[i] == "White":
                tree.append((vertex, i))
                pred[i] = vertex
                dfs_cal(adj_matrix, tree, forward, back, cross, i, number, color, pred)
                color[i] = "Black"
            elif color[i] == "Grey":
                back.append((vertex, i))
            elif color[i] == "Black":
                if is_cross(vertex, i, pred):
                    cross.append((vertex, i))
                else:
                    forward.append((vertex, i))
    color[vertex] = "Black"

def is_cross(i,j,pred):
    if(j==None):return True
    if(pred[j]==i):return False
    return is_cross(i,pred[j],pred)

def dfs(adj_matrix):
    tree = []
    forward = []
    back = []
    cross = []
    number = len(adj_matrix)
    color = ["White" for _ in range(number)]
    pred = [None for _ in range(number)]
    for i in range(number):
        if color[i] == "White":
            dfs_cal(adj_matrix, tree, forward, back, cross, i, number, color, pred)

    return sorted(tree), sorted(forward), sorted(back), sorted(cross)