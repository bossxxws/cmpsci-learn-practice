# 读取m和n的值  
m, n = map(int, input("请输入m和n（以空格隔开）: ").split())  

  
# 确保m和n都大于等于4  
if m < 4 or n < 4:  
    print("m和n都必须大于等于4")  
    exit()  
  
# 创建一个二维列表用于存储输入的数据  
grid = []  
for i in range(m):  
    row = list(map(int, input(f"请输入第{i+1}行的{n}个整数（以空格隔开）: ").split()))  
    if len(row) != n:  
        print("每行的整数数量必须与n相等")  
        exit()  
    grid.append(row)  
  
# 初始化行和列中2023的计数  
row_count = 0  
col_count = 0  
  
# 遍历二维数组，检查行和列中2023的个数  
for i in range(m):  
    for j in range(n):  
        if grid[i][j] == 2023:  
            row_count += 1  # 行中找到了2023  
            break  # 同一行中只查找一个2023  
  
# 检查列中2023的个数  
for j in range(n):  
    for i in range(m):  
        if grid[i][j] == 2023:  
            col_count += 1  # 列中找到了2023  
            break  # 同一列中只查找一个2023  
  
# 注意：由于题目说明同一行同一列中只能找到一个2023，我们不需要去重  
# 直接输出行和列中2023的总数  
print(row_count + col_count)

# 从键盘输入一个m，n，代表二维数组的行和列，输入m行数据，每行数据一共n个，用空格隔开。查找行和列中包括的2023的个数。（m和n均大于等于4，m和n可以不相等，且同一行同一列中只能找到一个2023）。
# example：
# input：
# 4 4
# 2 0 2 3
# 0 2 0 2
# 2 0 2 3
# 3 3 3 1
# output：
# 4