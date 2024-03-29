def evaluate_m(i):
    if i==1:
        return 1
    else:
        return 1/i+evaluate_m(i-1)