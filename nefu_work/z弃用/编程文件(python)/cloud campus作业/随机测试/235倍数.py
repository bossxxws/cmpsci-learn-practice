def count_multiples():
    count = 0
    for num in range(1, 101):
        if num % 2 == 0 or num % 5 == 0 or num % 3 == 0:
            count += 1
    return count

result = count_multiples()
print(result)