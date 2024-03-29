name_1 = str(input())

name_2 = str(input())

if len(name_1) != len(name_2) :

    print(1)

elif name_1 == name_2  :

    print(2)

elif name_1.upper() == name_2.upper() and name_1 != name_2 :

    print(3)

elif len(name_1) == len(name_2) and name_1.upper() != name_2.upper():

    print(4)
