def merge(list1, list2):
    lis = []
    i = 0
    j = 0
    while i < len(list1) and j < len(list2):
        if list1[i] <= list2[j]:
            lis.append(list2[j])
            j += 1
        else:
            lis.append(list1[i])
            i += 1
    if i < len(list1):
        for a in range(i, len(list1)):
            lis.append(list1[a])
    elif j < len(list2):
        for a in range(j, len(list2)):
            lis.append(list2[a])
    return lis