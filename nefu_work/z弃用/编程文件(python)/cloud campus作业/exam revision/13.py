def cumulative_prod(t):
    if t.left ==None and t.right==None:
        return t
    if t.left:
        t.data=t.data*cumulative_prod(t.left).data
    if t.right:
        t.data=t.data*cumulative_prod(t.right).data
    return t