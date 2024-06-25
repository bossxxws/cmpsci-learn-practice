def generate_words(filename):
    if filename == "":
        return "ERROR: Invalid filename!"

    try:
        with open(filename, 'r') as file:
            unique_words = []
            for line in file:
                words = line.strip().split()
                for word in words:
                    if len(word) >= 3:
                        if word[0].lower() + word[len(word) // 2].lower() + word[-1].lower() not in unique_words:
                            unique_words.append(word[0].lower() + word[len(word) // 2].lower() + word[-1].lower())
            return list(unique_words)
    except FileNotFoundError:
        return f"ERROR: The file '{filename}' does not exist."
