import math
n = input("n = ")
n = int(n)
result = 1 / (math.sqrt(5)) * (((((1 + math.sqrt(5)) / 2) ** n)) - ((1 - math.sqrt(5) / 2) ** n))
round(result)
print("result=",round(result))
