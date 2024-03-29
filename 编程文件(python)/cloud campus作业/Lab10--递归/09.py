def no_evens(numbers):
    if len(numbers) == 0:
        return True
    elif numbers[0] % 2 == 0:
        return False
    else:
        return no_evens(numbers[1:])
