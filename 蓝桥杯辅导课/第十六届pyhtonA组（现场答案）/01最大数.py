n = int(input("请输入n："))
binary_strs = [format(i, 'b') for i in range(1, n+1)]  # 生成二进制列表
combined = ''.join(binary_strs)                        # 拼接所有二进制
sorted_chars = sorted(combined, reverse=True)          # 字符降序排序
sorted_str = ''.join(sorted_chars)                     # 重组为字符串
decimal = int(sorted_str, 2)                           # 转为十进制
print("排序后的二进制拼接：", sorted_str)
print("转换后的十进制结果：", decimal)