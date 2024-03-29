#添加键值对
alien_0 = {"clor":"green", "points":"5"}
print(alien_0)
alien_0["x_position"] = 0
alien_0["y_position"] = 25
print(alien_0)
#修改字典中的值
alien_0 = {"clor" : "green", }
alien_0["color"] = "yellow"
print(alien_0["clor"])
#移动的外星人
alien_0 = {"x_position" : 0, "y_position" : 25, "speed" : "medium"}
if alien_0["speed"] =="slow":
    x_increment =       1000000
elif alien_0["speed"] == "medium" :
    x_increment =       2000000
else:
    x_increment =       3000000
alien_0["x_position"] = alien_0["x_position"] + x_increment
print(f"new x_position: {alien_0['x_position']}")
#删除键值对
alien_0 = {"clor":"green", "points":"5"}
print(alien_0)
del alien_0["points"]
print(alien_0)
#由类似对象组成的字典,使用get（）来访问数值
alien_0 = {"clor":"green", "speed":"low"}
point_value = alien_0.get("points","NO point value assigned")
print(point_value)
#遍历字典中的所有键值对
favourite_languages = {'jen' : 'python',
                       "sarah" :"c",
                       "edward" :"ruby",
                       "phil"  : "python" ,                     
    }
for name, language in favourite_languages.items():
    print(name+"                "+language)
#遍历字典中的所有键
favourite_languages = {'jen' : 'python',
                       "sarah" :"c",
                       "edward" :"ruby",
                       "phil"  : "python" ,                     
    }
for name in favourite_languages.keys():
    print(name)
for name in favourite_languages:
    print(name)
#方法kay（）不止可以用来遍历：实际上，它返回一个列表，其中包含字典中的所有键
favourite_languages = {'jen' : 'python',
                       "sarah" :"c",
                       "edward" :"ruby",
                       "phil"  : "python" ,                     
    }
if "erin" not in favourite_languages.keys():#核实‘erin’是否包含在这个列表
    print("Erin,please take our poll")
favourite_languages = {'jen' : 'python',
                       "sarah" :"c",
                       "edward" :"ruby",
                       "phil"  : "python" ,                     
    }
for name in sorted(favourite_languages):
    print(f"{name.title()},thank you for taking the poll")
#或者显式地使用keys（）
for name in sorted(favourite_languages.keys()):
    print(f"{name.title()},thank you for taking the poll")
#嵌套 字典列表
alien_0 = {"color" : "green" , "points" : 5}
alien_1 = {"color" : "yellow" , "points" : 10}
alien_2 = {"color" : "red" , "points" : 15}
aliens = [alien_0, alien_1, alien_2]
for alien  in aliens:
    print(alien)
print(aliens)
#生成30个外星人
aliens = []
for alien_number in range(30):
    new_alien = {"color": "green", "points": 5, "speed": "slow"}
    aliens.append(new_alien)
#显示前五个外星人
for alien in aliens[:5]: 
    print(alien)
print(f"Total number of  aliens :{len(aliens)} ")
#修改外星人数据
for alien in aliens[0:3]:
    if alien["color"] == "green":
        alien["color"] = "yellow"
        alien['speed'] = 'medium'
        alien["points"] = 10
for alien in aliens[:5]:
    print(alien)
#在字典中存储列表 一个键关联到多个值的时候可以嵌套一个列表
#存储所点披萨的信息、
#1）
pizza = {
    "crust": "thick",
    "toppings": ["mushrooms","extra cheese"],
}
print(f"You ordered a {pizza['crust']}-crust pizza""with the following toppings")
for topping in pizza["toppings"]:
    print("\t" + topping)
print(pizza["toppings"])
#2）
favourite_languages = {
    'jen' : ['python','ruby'],
    'sarah': ['c'],
    'edward': ["ruby", "go"],
    'phil': ["python", "haskell"], 
    }
for name , languages in favourite_languages.items():
    print(f"{name.title()}'s favourite languages are:")
    for language in languages:
        print(f"\t{language.title()}")
#在字典中存储字典
users = {
    'aeintein':{
    "first":'albert',
    "last":"einstein",
    "location":"princeton",
    },
    "mcurie":{
    "first":"marie",
    "last":"curie",
    "location":"paris",
    },
}
for username,unserinfo in users.items():
    print(f"\n{username.title()}")
    full_name = f"{unserinfo['first']} {unserinfo['last']}"
    location = unserinfo["location"]
    print(f"Full name:{full_name.title()}")
    print(f"\tLocation:{location.title()}")
#结束












    