def get_gcd(m, n):
    if n == 0:
        return m
    return get_gcd(n, m % n)