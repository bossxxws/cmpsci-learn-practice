def decimal_to_binary(decimal_num):
    if decimal_num <= 0:
        return ""
    binary_num = decimal_to_binary(decimal_num // 2)  
    return binary_num + str(decimal_num % 2)  
print(decimal_to_binary(6)[::1])