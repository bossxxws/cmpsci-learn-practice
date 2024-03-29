def greet(uers) :
    for name in uers:
        msg = f"Hello!{name.title()}"
        print(msg)
 
usernames = ["weiqing","zhangao","jixiaoyu"]
greet(usernames)