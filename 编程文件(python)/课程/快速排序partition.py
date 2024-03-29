def partition(int_list,star,end):
    l = len(int_list)
    pivot=int_list[l-1]
    indexi=0
    indexj=0
    while indexj<l-1:
        if int_list[indexj]<pivot:
            tem = int_list[indexi]
            int_list[indexi]=int_list[indexj]
            int_list[indexj]=tem
            indexj+=1
            indexi+=1
        else:
            indexj+=1
    tem=int_list[indexi]
    int_list[indexi]=pivot
    int_list[l-1]=tem
    
        

    