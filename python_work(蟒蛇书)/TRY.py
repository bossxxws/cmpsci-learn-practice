s=int(input("请输入一个正整数："))
def isprime(s):
    if s<2 :
        return False 
    else:
        for i in range(2,s):
            if s%i==0:
                return False
                break
        else:
            return True
print(isprime(s))

