def convert_tree_to_list(b_tree):
    if b_tree is None:
        return None
    root_data = b_tree.get_data()
    left_subtree = convert_tree_to_list(b_tree.get_left())
    right_subtree = convert_tree_to_list(b_tree.get_right())
    return [root_data, left_subtree, right_subtree]