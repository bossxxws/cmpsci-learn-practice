#返回函数
#说白了，函数就是个你招来的工人。你给他一些材料，告诉他怎么用这些材料拼装，然后他负责把拼装好的成品交给你。
#材料就是函数的参数，成品是函数的输出，而怎么拼装就是你写的函数体代码了。
#比如这段代码def worker(a, b, c):
#    x = a + b
#    y = x * c
#这个工人（worker）在你的指导下，用a b c三个材料，装配出了x和y两个成品。但是程序里的装配和工厂不同，用过的材料不会消失。
#这样，这个工人手里就有了a b c x y五样物品。他怎么知道你要的是哪个呢？
#所以return的作用就是，在这种时候告诉工人你到底想要什么东西，是一个iPhone手机壳还是整台iPhone。
#例如def worker(a, b, c):
#    x = a + b
#    y = x * c
#    return y这样工人就会把y交给你。当你让这个工人帮你干活（调用函数的时候）result = worker(1, 2, 3)你就会得到对应的结果（(1+2)*3）。
#这就是return的作用。
#让实参变成可选的
def get_formated_name(first_name, last_name, middle_name = ""):
    if middle_name: #函数把非空字符串解读为True
        full_name = f"{first_name} {middle_name} {last_name}"
    else:
        full_name = f"{first_name} {last_name}"
    return full_name.title()
musician = get_formated_name('jimi','dark')
print(musician)
musician = get_formated_name('ji','yu','xiao')
print(musician)
