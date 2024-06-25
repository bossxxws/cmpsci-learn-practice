def palindrome_filter(sentence):
    def filter_helper(char):
        if char.isalpha():
            return char.lower()
        return ''

    if sentence == '':
        return ''
    
    first_char = filter_helper(sentence[0])
    rest_of_string = palindrome_filter(sentence[1:])
    
    return first_char + rest_of_string


def is_palindrome(sentence):
    if len(sentence) <= 1:
        return True
    
    if sentence[0] == sentence[-1]:
        return is_palindrome(sentence[1:-1])
    
    return False
print(is_palindrome(palindrome_filter("KAAAAK.")))