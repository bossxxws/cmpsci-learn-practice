def matrix_power(m, A, n):
    result = A
    for _ in range(n-1):  # 进行 n-1 次幂运算
        result = matrix_multiply(result, A)
    return result

def matrix_multiply(A, B):
    rows_A = len(A)
    cols_A = len(A[0])
    cols_B = len(B)
    result = [[0] * cols_B for _ in range(rows_A)]  # 创建结果矩阵

    for i in range(rows_A):
        for j in range(cols_B):
            for k in range(cols_A):
                result[i][j] += A[i][k] * B[k][j]

    return result

# 从键盘获取输入
m = int(input())
A = []
for _ in range(m):
    row = list(map(int, input().split()))
    A.append(row)
n = int(input())

# 计算矩阵的幂运算结果
result = matrix_power(m, A, n)
print(result)
print("")
[[2, 2], [2, 2]]
[[2, 2], [2, 2]]