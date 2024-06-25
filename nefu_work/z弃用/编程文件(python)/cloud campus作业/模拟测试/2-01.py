n = int(input("Enter a number: " ))
if n<10:
    print(f"The least significant digit of {n} is {n}.")
elif 9<n<100:
    k=n%100
    s=k%10
    print(f"The least significant digit of {n} is {s}.")
else:
    k=n%1000
    s=k%100
    r=s%10
    print(f"The least significant digit of {n} is {r}.")