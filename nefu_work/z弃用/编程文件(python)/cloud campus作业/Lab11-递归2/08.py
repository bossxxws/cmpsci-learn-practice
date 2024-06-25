def collatz(n):
    print(n)
    
    if n == 1:
        return
    
    if n % 2 == 0:
        collatz(n // 2)
    else:
        collatz(n * 3 + 1)


