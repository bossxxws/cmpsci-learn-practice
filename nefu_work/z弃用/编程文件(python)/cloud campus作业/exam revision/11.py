def cumulative_sum(node):
    aux=node
    res=0
    while aux.next:
        res+=aux.data
        aux=aux.next
    return res