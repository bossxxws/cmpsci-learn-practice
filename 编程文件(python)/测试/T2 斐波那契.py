n = int(input())
fn1 = 1
fn2 = 1
print(fn1, fn2, end="")
while n > 2 :
    fn = fn1 + fn2
    print("",str(fn),end="")
    fn1 = fn2
    fn2 = fn
    n = n - 1

