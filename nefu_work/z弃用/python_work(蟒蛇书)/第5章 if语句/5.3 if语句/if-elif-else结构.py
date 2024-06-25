age_1 = 12
if age_1 < 4:
    print("Your admission cost is $0")
elif age_1 < 18:
    print("Your admission cost is $25")
else:
    print("Your admission cost is $40")

age_2 = 3 #简洁写法
if age_2 < 4:
    price = 0
elif age_2 < 18:
    price = 25
else:
    price = 40
print(f"\nYour admission cost is ${price}")

age_3 = 2 #使用多个elif代码块
if age_3 < 4:
    price = 0
elif age_3 < 18:
    price = 25
elif age_3 < 65:
    price = 40
else:
    price = 20
print(f"\nYour admission cost is ${price}")

age_4 = 101 #省略else代码块
if age_4 < 4:
    price = 0
elif age_4 < 18:
    price = 25
elif age_4 < 65:
    price = 40
elif age_4 <80:
    price = 20
elif age_4 < 120:
    price = -666
print(f"\nYour admission cost is ${price}")






    