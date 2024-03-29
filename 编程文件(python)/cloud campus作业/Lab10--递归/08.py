def get_max_len_list(words):
    if len(words)==1:
        return len(words[0])
    else:
        if len(words[0])>get_max_len_list(words[1:]):
            return len(words[0])
        else:
            return get_max_len_list(words[1:])