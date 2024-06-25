def count_words_of_length(filename, number):
    if filename == '':
        return "ERROR: Invalid filename!"
    try:
        with open(filename, 'r') as file:
            words = file.read().split()
            count = 0
            for word in words:
                if len(word) == number:
                    count +=1
            return count
    except FileNotFoundError:
        return f"ERROR: The file '{filename}' does not exist."

  