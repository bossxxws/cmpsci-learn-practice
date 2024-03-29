def find_node(bst, value):
    if bst.data == value:
        return bst
    elif value < bst.data and bst.left != None:
        return find_node(bst.left, value)
    elif value > bst.data and bst.right != None:
        return find_node(bst.right, value)
    else:
        return None
def get_list_beneath(bst, value):
    node = find_node(bst, value)  
    if node is None:
        return []  
    result = [] 

    def traverse(node):
        nonlocal result
        if node is None:
            return

        traverse(node.get_left())  
        result.append(node.get_data()) 
        traverse(node.get_right())  

    traverse(node.get_left())
    traverse(node.get_right())

    return result