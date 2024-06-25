def get_sum_of_neighbours(a_list):
    l=len(a_list)
    newl  =[]
    for i in range(0,l):
        if i == 0:
            tep = a_list[1]
        elif i == l-1:
            tep = a_list[l-2]
        else:
            tep=a_list[i-1]+a_list[i+1]
        newl.append(tep)
    return newl
