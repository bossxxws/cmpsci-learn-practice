'''
def get_list(tree):
    if tree ==None:
        return []
    if tree.left==None and tree.right==None:
        return [tree.data]
    res=[]
    if tree.left:
        res.append(get_list(tree.left))
    res.append(tree.data)
    if tree.right:
        res.append(get_list(tree.right))
    return res
'''
def get_list(tree):
    if tree.left is None and tree.right is None:
        return [tree.data]

    result = []
    if tree.left:
        result.extend(get_list(tree.left))
    result.append(tree.data)
    if tree.right:
        result.extend(get_list(tree.right))

    return result
