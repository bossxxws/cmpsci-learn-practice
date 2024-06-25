def get_sum_ascii(word):
    if len(word)==1:
        return ord(word[0])
    else:
        return ord(word[0])+get_sum_ascii(word[1:])
