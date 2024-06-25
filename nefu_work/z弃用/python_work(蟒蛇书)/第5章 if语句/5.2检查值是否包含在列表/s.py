banned_users = ["zhangao", "weiqing", "jasper"]
user = input()
if user not in banned_users:
    print(f"\n{user.title()}, you can post a response as you wish")
if user in banned_users:
    print('Fuck off')
    