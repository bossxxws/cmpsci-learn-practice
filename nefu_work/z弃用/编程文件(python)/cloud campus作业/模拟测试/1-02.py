def get_min_abs_distance(a_list):
    min = a_list[0]-a_list[1]
    l = len(a_list)
    if min<0:
            min = abs(min)
    for i in range(0,l-1):
        tep = a_list[i]-a_list[i+1]
        if tep<0:
            tep = -tep
        if tep<min:
            min = tep
    return min
