def get_first_lower_case(word):
    if word =='':
        return None
    elif word[0].islower():
        return word[0]
    else:
        return get_first_lower_case(word[1:])
s = 'Wdone'
print(get_first_lower_case(s))

