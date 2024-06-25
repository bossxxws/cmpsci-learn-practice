def rate(n):
    count = 0
    total = 0
    count +=1
    i = 0
    count +=1
    count +=1
    while i < 4:
        count +=1
        j = 0
        count +=1
        while j < i:
            count +=1
            total += j
            count +=1
            j += 1
            count +=1
        i += 1
        count +=1
        count +=1
    count +=1
    
    print(f"Number of operations: {count}")
rate(2)