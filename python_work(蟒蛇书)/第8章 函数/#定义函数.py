#定义函数
def greet_user(username):
    """显示简单的问候语"""
    print(f"Hello,{username.title()}!")
greet_user('jesse')
#多次调用函数
def descirbe_pet1(animal_type,pet_name1):
    """显示宠物信息"""
    print(f"\nI have a {animal_type}.")
    print(f"My pet's name is {pet_name1}.")
descirbe_pet1("fish","冀小鱼")
#关键字实参
descirbe_pet1(animal_type="fish",pet_name1="寄小鱼")
#默认值，没有给形参传递指令时，将根据默认值赋予实参
def describe_pet2(pet_name2,animal_type = "dog"):
    print(f"i have a {animal_type.title()}")
    print(f"It's name is {pet_name2}")
describe_pet2("jixiaoyu")
