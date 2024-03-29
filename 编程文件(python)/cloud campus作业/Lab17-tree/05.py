def count_nodes(b_tree):
    if b_tree==None:
        return 0
    l=count_nodes(b_tree.get_left())
    r=count_nodes(b_tree.get_right())
    return l+r+1     