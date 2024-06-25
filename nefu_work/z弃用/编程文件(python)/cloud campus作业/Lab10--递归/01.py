def count_down(n):
    if n==0:
        print("Go!")
    else:
        print(n)
        count_down(n-1)
