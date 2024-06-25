def get_sum_digits(number):
    if number<10:
        return number
    elif 9<number<100:
        return number//10+get_sum_digits(number%10)
    elif 99<number<1000:
        return number//100+get_sum_digits(number%100)
    else:
        return number//1000+get_sum_digits(number%1000)