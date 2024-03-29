EPSILON = 1e-15
c = float(input())
t = c
while abs(t - c / t) > EPSILON * t :
    t = (c / t + t) / 2.0
print(t)
