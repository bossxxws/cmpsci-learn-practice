def count_evens(my_list):
    count = 0

    for item in my_list:
        if isinstance(item, int) and item % 2 == 0:
            count += 1
        elif isinstance(item, list):
            count += count_evens(item)  
        

    return count