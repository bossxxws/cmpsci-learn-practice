def get_sum(n):
    if n==1:
        return n
    else:
        return n+get_sum(n-1)
print(get_sum(6))