def binary_search(values, item):
    if len(values) == 0:
        return False
    
    mid = len(values) // 2
    print(values[:mid], values[mid], values[mid+1:])
    
    if values[mid] == item:
        return True
    elif values[mid] > item:
        return binary_search(values[:mid], item)
    else:
        return binary_search(values[mid+1:], item)
