#使用while处理列表和字典
#在列表之间移动元素
unconfirmed_users = ['alice', 'brain', 'candace']
confirmed_users = []
while unconfirmed_users:
    current_user = unconfirmed_users.pop()
    print(f"Verifying user : {current_user.title()}")
    confirmed_users.append(current_user)
print(f"\nThe following users have been confirmed:")
for confirmed_user in confirmed_users:
    print(confirmed_user)