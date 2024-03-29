def index_of_closest(a_list, number):
    l = len(a_list)
    cha = abs(a_list[0]-number)
    chai=0
    for i in range(0,l):
        k = abs(a_list[i]-number)
        if k < cha:
            cha = k
            chai = i
    return chai
        
