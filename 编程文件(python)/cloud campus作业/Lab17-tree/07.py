def get_max(b_tree, is_integer):
    if(is_integer):
        if b_tree==None:
            return 0
        elif b_tree.get_left() ==None and b_tree.get_right()==None:
            return b_tree.get_data()
        else:
            l=get_max(b_tree.get_left(), is_integer)
            r=get_max(b_tree.get_right(), is_integer)
            cmax=max(l,r,b_tree.get_data())
            return cmax
    else:
        if b_tree==None:
            return 'a'
        elif b_tree.get_left() ==None and b_tree.get_right()==None:
            return b_tree.get_data()
        else:
            l=get_max(b_tree.get_left(), is_integer)
            r=get_max(b_tree.get_right(), is_integer)
            cmax=max(l,r,b_tree.get_data())
            return cmax