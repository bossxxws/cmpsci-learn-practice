def translate_word(dictionary, word):
    if word in dictionary:
        return f"'{word}' is translated into '{dictionary[word]}'."
    else:
        return "Sorry that word doesn't exist in Maori!"

def build_dictionary(file_name):
    dictionary = {}
    with open(file_name, 'r') as file:
        for line in file:
            line = line.strip()
            if line:
                english, maori = line.split(':')
                dictionary[english] = maori
    return dictionary

def main():
    file_name = input("Enter the English to Maori dictionary filename: ")
    dictionary = build_dictionary(file_name)

    word = input("Enter an English word: ")
    translation = translate_word(dictionary, word)
    print(translation)

if __name__ == '__main__':
    main()