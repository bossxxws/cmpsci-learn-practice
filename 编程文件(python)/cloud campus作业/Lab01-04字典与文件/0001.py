w1 = input("Enter a word: ")
w2 = input("Enter another word: ")
L1 = list(w1)
L2 = list(w2)
L3 = sorted(L1)
L4 = sorted(L2)
print(L3,L4)
if len(L3) != len(L4) or L3 != L4:
    print(f"{w1} and {w2} are not anagrams of each other.")
else:
    print(f"{w1} and {w2} are  anagrams of each other.")
