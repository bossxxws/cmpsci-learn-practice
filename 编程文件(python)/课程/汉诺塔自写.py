def move(n,source,cure,aim):
    if n == 1:
        print(f"move 1 from {source} to {aim}")#基本情况
    else:
        move(n-1,source,aim,cure)#超级操作：把上面n-1个全部移动到辅助柱子 最后都会过到剩最上面一个（n=1）的时候移动到想要的柱子最后实现目标
        print(f"move {n} from {source} to {aim} ")#微操作，把最下面的一个n移动到目标柱上
        move(n-1,cure,source,aim)#超级操作：把辅助柱子上的n-1个全部移动到目标柱
move(int(input()),"A","B","C")