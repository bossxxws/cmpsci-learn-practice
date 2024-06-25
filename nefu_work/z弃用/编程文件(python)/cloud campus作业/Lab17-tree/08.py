def is_full(my_tree):
    if my_tree==None:
        return False
    if my_tree.get_right() ==None and my_tree.get_left()==None:
        return True
    r=is_full(my_tree.get_right())
    l=is_full(my_tree.get_left())
    return l and r