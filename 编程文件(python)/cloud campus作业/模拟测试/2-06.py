def rate(n):
    cou =1
    total = 0
    cou +=1
    i = 0
    cou +=1
    while i < 10:
        cou +=1
        cou +=1
        total += i
        cou +=1
        i += 1
    cou +=1
    i = 0
    cou +=1
    while i < n:
        cou +=1
        cou +=1
        j = n
        cou +=1
        while j > 0:
            cou +=1
            cou +=1
            total += 1
            cou +=1
            j -= 2
        cou +=1
        i += 2
    cou +=1
    print(f"Number of operations: {cou}")