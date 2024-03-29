def create_tree_from_nested_list(a_list):
    if a_list is None:
        return None
    root_data = a_list[0]
    left_subtree = create_tree_from_nested_list(a_list[1])
    right_subtree = create_tree_from_nested_list(a_list[2])
    tree = BinaryTree(root_data)
    tree.set_left(left_subtree) 
    tree.set_right(right_subtree) 
    return tree