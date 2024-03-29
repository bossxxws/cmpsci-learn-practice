def rate(n):
    count = 0
    i = 0
    count +=1
    total = 0
    count +=1
    count +=1
    while i < 10:
        count +=1
        j = 0
        count +=1
        while j < n:
            count +=1
            total += j
            count +=1
            j += 1
            count +=1
        i += 1
        count +=1
        count +=1
    count +=1
    return count
print(rate(100))