n = int(input())
total_e = 1
for i in range(1,n+1):
    sum = 1
    for j in range(1,i+1):
        sum *= j
    total_e += 1 / sum
print(total_e)
