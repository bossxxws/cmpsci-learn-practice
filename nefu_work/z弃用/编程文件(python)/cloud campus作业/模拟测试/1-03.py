def modify_list(words_list):
    l = len(words_list)
    for i in range(0,l):
        words_list[i] = words_list[i][i+1::]
    return words_list