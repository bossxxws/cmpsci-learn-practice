def create_a_tree():
    b_tree=BinaryTree(9)
    b_tree.insert_left(3)
    b_tree.insert_right(6)
    l=b_tree.get_left()
    r=b_tree.get_right()
    l.insert_right(7)
    r.insert_right(2)
    return b_tree