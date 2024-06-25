def get_max_list(numbers):
    if len(numbers)==1:
        return numbers[0]
    else:
        if numbers[0]>get_max_list(numbers[1:]):
            return numbers[0]
        else:
            return get_max_list(numbers[1:])