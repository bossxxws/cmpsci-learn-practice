import math
a = float(input())
p = float(input())
m1 = float(input())
m2 = float(input())
G = (4 * (math.pi ** 2) * (a ** 3)) / ((p ** 2) * (m1 + m2))
print("%.2f" % G)
