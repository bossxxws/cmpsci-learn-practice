def reverse_string(word):
    if len(word)==0:
        return word
    else:
        return word[len(word)-1]+ reverse_string(word[:len(word)-1])

