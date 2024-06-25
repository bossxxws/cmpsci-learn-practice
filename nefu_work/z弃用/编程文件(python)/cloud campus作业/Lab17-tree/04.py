def get_height(b_tree):
    if b_tree == None:
        return -1
    left = get_height(b_tree.get_left())
    right = get_height(b_tree.get_right())
    return max(left, right) + 1