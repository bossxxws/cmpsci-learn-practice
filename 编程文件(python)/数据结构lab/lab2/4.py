def pivot(mylist, l, r):
    return r

def partition(mylist, l, r, pivot_index):
    mylist[pivot_index], mylist[r] = mylist[r], mylist[pivot_index]
    k = l
    for i in range(l, r+1):
        if mylist[i] < mylist[r]:
            mylist[k], mylist[i] = mylist[i], mylist[k]
            k += 1
    mylist[k], mylist[r] = mylist[r], mylist[k]
    return k

def quicksort(mylist, l, r):
    if l < r:
        pi = pivot(mylist, l, r)
        k = partition(mylist, l, r, pi)
        print("pivot="+str(mylist[k])+" "+"L="+str(l)+" "+"R="+str(r))
        print(mylist)
        quicksort(mylist, l, k - 1)
        quicksort(mylist, k + 1, r)