def shrinks(tree):
    if tree is None:
        return True

    left_child = tree.get_left()
    right_child = tree.get_right()

    if (left_child is not None and left_child.get_data() >= tree.get_data()) or (right_child is not None and right_child.get_data() >= tree.get_data()):
        return False

    return shrinks(left_child) and shrinks(right_child)