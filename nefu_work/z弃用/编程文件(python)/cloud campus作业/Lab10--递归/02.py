def copy_string(word):
    if len(word) == 0:
        return word
    else:
        return word[0] + copy_string(word[1:])


    