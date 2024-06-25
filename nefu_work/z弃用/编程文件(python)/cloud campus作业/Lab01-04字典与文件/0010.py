sentence = input("May your coffee be strong and your Monday be short")
lst = list(sentence)
dictionary = {}
for i in range(1,1000):
    for j in range(1,10):
        if i == len(lst[j]):
            if i in dictionary:
                dictionary[i] = dictionary[i] + lst[j]
            else:
                dictionary[i] = lst[j]
        if dictionary[i]:
            print(i,' '.join(sorted(dictionary[i])))
    





    