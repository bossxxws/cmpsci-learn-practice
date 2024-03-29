players = ["zhangxinyu", 'jixiaoyu', 'wangxudong', 'weiqing', 'zhangao', 'lilingyu' ]
print(players[0:4])
print(players[:4])
print(players[2:])
print(players[-3:])
#遍历切片
print("\n")
print("Here are the first three players on my team:")
for player in players[0:3]:
    print(player.title())
#复制列表
players = ["zhangxinyu", 'jixiaoyu', 'wangxudong', 'weiqing', 'zhangao', 'lilingyu' ]
copy = players[:]
copy.append("wangqiutong")
players.append("lvzhuoyang")
print("\n")
print(players)
print(copy)
