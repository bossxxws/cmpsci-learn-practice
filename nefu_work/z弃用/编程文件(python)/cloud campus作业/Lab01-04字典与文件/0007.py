def count_consonants(word):
    total = ["B", "C", "D","F","G", "H","J", "K", "L", "M", "N", "P", "Q","R", "S", "T","V", "W", "X", "Y", "Z"]
    count = 0
    for wor in word :
        daxie = wor.upper()
        if daxie in total:
            count = count + 1
    return count
l = count_consonants("")
print(l)