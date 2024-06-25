def join_multiply(first_list, second_list, result_list):
    if len(first_list) == 0:
        return
    
    multiply_elements(first_list[0], second_list, result_list)
    join_multiply(first_list[1:], second_list, result_list)


def multiply_elements(num, second_list, result_list):
    if len(second_list) == 0:
        return
    
    result_list.append(num * second_list[0])
    multiply_elements(num, second_list[1:], result_list)

