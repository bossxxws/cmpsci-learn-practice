def rate(n):
    count = 0
    
    total = 0
    count +=1
    i = 1
    count +=1
    count +=1
    while i < n:
        count +=1
        j = 0
        count +=1
        while j < n:
            count +=1
            total += j 
            count +=1
            j += 1
            count +=1
        
        i *= 2
        count +=1
        count +=1
    count +=1
    print(f"Number of operations: {count}")
rate(128)
