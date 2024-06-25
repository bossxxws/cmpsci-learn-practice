def count_consonants(word):
    if word == '':
        return 0
    elif word[0] in 'bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ':
        return 1 + count_consonants(word[1:])
    else:
        return count_consonants(word[1:])

        
