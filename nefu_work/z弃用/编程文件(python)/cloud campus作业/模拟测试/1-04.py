def get_first_mid_last(words_list):
    newl = []
    for word in words_list:
        word =word.lower()
        l = len(word)
        neww = ""
        if len(word)>=3:
                neww = word[0]+word[l//2]+word[l-1]
        else:
            continue
        newl.append(neww)
    return newl