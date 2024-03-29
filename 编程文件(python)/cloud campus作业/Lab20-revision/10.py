def is_subtree(tree1, tree2):
    if tree1 is None:
        return False

    if are_identical(tree1, tree2):
        return True

    return is_subtree(tree1.get_left(), tree2) or is_subtree(tree1.get_right(), tree2)

def are_identical(tree1, tree2):
    if tree1 is None and tree2 is None:
        return True

    if tree1 is None or tree2 is None:
        return False

    if tree1.get_data() != tree2.get_data():
        return False

    return are_identical(tree1.get_left(), tree2.get_left()) and are_identical(tree1.get_right(), tree2.get_right())