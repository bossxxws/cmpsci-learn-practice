n = input()
n = n.lower()
count_1 = 0
count_2 = 0
count_3 = 0
count_4 = 0
count_5 = 0
for k in n :
    if k == "a"  :
        count_1 +=  1
    if k == "e"   :
        count_2 +=  1
    if k == "i" :
        count_3 +=  1
    if k == "o"  :
        count_4 +=  1
    if k == "u" :
        count_5 +=  1
lst1 = [['a',count_1]]
lst2 = [['e',count_2]]
lst3 = [['i',count_3]]
lst4 = [['o',count_4]]
lst5 = [['u' , count_5]]
lst_sum = lst1 + lst2 + lst3 + lst4 + lst5
print(lst_sum)


