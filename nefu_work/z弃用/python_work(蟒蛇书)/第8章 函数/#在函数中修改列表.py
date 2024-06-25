#在函数中修改列表
unprinted_designs = ["jixiaoyu",'weiqing','wangxudong']
printed_designs = []
def printdesigns(unprinteddesigns,printed_designs) :
    while unprinted_designs:
        current_designs = unprinteddesigns.pop()
        print(f"printing:{current_designs}")
        printed_designs.append(current_designs)
    print("The following designs are printed:")
    for printeddesign in printed_designs:
        print(printeddesign)
printdesigns(unprinted_designs,printed_designs)
