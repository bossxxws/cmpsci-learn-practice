count_number = 0
n = input()
lst1 = n.split()
for i in len(lst1):
    count_number += count_number + 1
    if count_number > 30 :
        print("impossible")
        break

