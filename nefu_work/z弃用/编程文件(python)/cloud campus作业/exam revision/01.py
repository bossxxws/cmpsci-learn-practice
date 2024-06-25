def print_border(word, spaces):
    l=len(word)
    zong=l+spaces*2+2
    print('*'*zong)
    print('*',end=" "*spaces)
    print(word,end="")
    print(" "*spaces,end="")
    print('*')
    print('*'*zong)
