number = int(input())
i = 2
while i < number :
    if number % i == 0 :
        break
    i = i + 1
if i == number :
    print("{} is a prime".format(number))
else:
    print("{} is not a prime".format(number))
