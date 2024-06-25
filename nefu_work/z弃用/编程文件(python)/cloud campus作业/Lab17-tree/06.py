def search(tree, item):
    if tree==None:
        return False
    if(tree.get_data()==item):
        return True
    return search(tree.get_left(),item) or search(tree.get_right(),item)