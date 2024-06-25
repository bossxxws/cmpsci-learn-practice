def dfs(adj_matrix):
    tree = []
    forward = []
    back = []
    cross = []
    number = len(adj_matrix)
    color = ["White" for _ in range(number)]
    for i in range(number):
        if color[i] == "White":
            dfs_compute(adj_matrix,tree,forward,back,cross,i,number,color)

    return sorted(tree), sorted(forward), sorted(back), sorted(cross)

def dfs_compute(adj_matrix,tree,forward,back,cross,vertex,number,color):
    stack = []
    pred = [None for _ in range(number)]
    stack.append(vertex)
    color[vertex] = "Grey"
    while len(stack) != 0:
        cur = stack[len(stack)-1]
        find = False
        for i in range(number):
            if adj_matrix[cur][i] == 1:
                # print(cur,i)
                # print(color[cur],color[i])
                if color[i] == "White":
                    stack.append(i)
                    pred[i] = cur
                    find = True
                    tree.append((cur,i))
                    color[i] = "Grey"
                    break
                elif color[i] == "Grey":
                    if (cur,i) not in back:
                        back.append((cur,i))
                elif color[i] == "Black":
                    if (cur,i) not in tree:
                        if is_cross(cur,i,pred):
                            if (cur,i) not in cross:
                             cross.append((cur,i))
                        else:
                            if (cur,i) not in forward:
                                forward.append((cur,i))
        if not find:
            color[cur] = "Black"
            stack.pop()
def is_cross(cur,des,pred):
    current = cur
    father = pred[current]
    while father != None:
        if father == des:
            return False
        current = father
        father = pred[current]
    current = des
    father = pred[current]
    while father != None:
        if father == cur:
            return False
        current = father
        father = pred[current]
    return True


# adj_matrix = [[0,1,1,1],[0,0,0,1],[0,0,0,1],[0,0,0,0]]
# tree, forward, back, cross = dfs(adj_matrix)
# print('Tree arcs: {}'.format(tree))
# print('Forward arcs: {}'.format(forward))
# print('Back arcs: {}'.format(back))
# print('Cross arcs: {}'.format(cross))

# adj_matrix = [[0, 1, 0], [0, 0, 0], [0, 0, 0]]
# tree, forward, back, cross = dfs(adj_matrix)
# print('Tree arcs: {}'.format(tree))
# print('Forward arcs: {}'.format(forward))
# print('Back arcs: {}'.format(back))
# print('Cross arcs: {}'.format(cross))

# adj_matrix = [[0, 0, 0, 0, 1, 0],
#               [1, 0, 1, 1, 0, 0],
#               [0, 0, 0, 0, 0, 0],
#               [0, 0, 0, 0, 0, 1],
#               [1, 0, 0, 0, 0, 0],
#               [0, 1, 1, 1, 0, 0]]
# tree, forward, back, cross = dfs(adj_matrix)
# print('Tree arcs: {}'.format(tree))
# print('Forward arcs: {}'.format(forward))
# print('Back arcs: {}'.format(back))
# print('Cross arcs: {}'.format(cross))
