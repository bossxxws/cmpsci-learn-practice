def selection_sort(data):
    count = 0
    for pass_num in range(len(data)-1, 0, -1):
        max = 0
        for i in range(1, pass_num+1):
            if data[i] > data[max]:
                max = i
        if max != pass_num:
            data[pass_num], data[max] = data[max], data[pass_num]
            count += 1
    return count
        
        