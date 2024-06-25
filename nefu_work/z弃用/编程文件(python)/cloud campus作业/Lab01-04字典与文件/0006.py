def get_sum_positive_even(numbers):
    jieguo = 0
    for num in numbers:
        if num > 0 and num % 2 == 0:
            jieguo += num
    return jieguo