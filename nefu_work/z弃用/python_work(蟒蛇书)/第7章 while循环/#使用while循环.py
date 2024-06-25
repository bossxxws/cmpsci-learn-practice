#使用while循环
cureent_number = 1
while cureent_number <= 5:
    print(cureent_number)
    cureent_number += 1
#让用户选择何时退出
prompt = "\nTell me something, and I will repeat it back to you :"
prompt = "\nEnter 'quit' to end the program."
message = ""
while message !=  "quit":
    message = input(prompt)
    if message != "quit" :
        print(message)


