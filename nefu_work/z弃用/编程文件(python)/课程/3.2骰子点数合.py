import random
number = 0
i = 1
while i<=100:
    dice_number=random.randrange(1,7)
    if dice_number==1:
        dice_number+=1
    i = i + 1
print(dice_number)
