def evaluate_f(n):
    if n==0:
        return 3
    elif n==1:
        return 2
    else:
        return 2*evaluate_f(n-1)+3*evaluate_f(n-2)