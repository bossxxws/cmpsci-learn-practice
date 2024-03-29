def get_list_of_ascending_elements(my_linked_list):
    result = []
    current = my_linked_list.get_head()
    maximum = float("-inf")  # Initialize the maximum as negative infinity
    
    while current is not None:
        data = current.get_data()
        if data > maximum:
            result.append(data)
            maximum = data
        current = current.get_next()
    
    return result