def get_min_odd(numbers):
    #返回最小奇数,没有就返回9999
    if len(numbers)==0:
        return 9999
    else:
        if numbers[0]%2!=0 and numbers[0]<get_min_odd(numbers[1:]):
            return numbers[0]
        else:
            return get_min_odd(numbers[1:])

        