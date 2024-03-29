
for i in range (200,301):
    if i % 5 ==0 and i % 3 != 0 :
        print(f"{i}",end="")
        if i != 295 :
            print(",",end="")