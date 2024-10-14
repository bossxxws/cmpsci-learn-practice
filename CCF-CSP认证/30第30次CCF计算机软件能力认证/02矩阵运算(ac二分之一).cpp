#include <iostream>
#include <map>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e4;
const int D = 22;

int Q[N][D], K[N][D], V[N][D], RK[D][N];

int W[N];

int n, d;

int ures[N][D]; // 分别表示结果的行和列

map<PII, int> res; // 存储n*n的矩阵

// nXd * d*N=N*N 得出一个NxN的矩阵

void work1() // Q和RK的乘法 是一个nxd 和 dxn的乘法
{
    for (int i = 1; i <= n; i++) // 枚举后一个矩阵需要乘的列数
    {
        for (int j = 1; j <= n; j++) // 每一列都要乘前一个矩阵的每一行
        {
            int t = 0;
            for (int k = 1; k <= d; k++) // 都是d和d的乘法
            {
                t += RK[k][i] * Q[j][k];
            }
            res[make_pair(j, i)] = t;
        }
    }
}

void work2() // 向量w和矩阵的乘积
{
    // 对于nxn矩阵中的第i行中的每一个元素，都与w向量中的第i个元素相乘
    for (int i = 1; i <= n; i++) // 枚举w中的每一个元素，以及相对的nxn矩阵中的每一行
    {
        // 对于wi，和无序映射res（并非真正的res）中的每一个元素都相乘
        for (int j = 1; j <= n; j++)
        {
            PII t = make_pair(i, j);
            res[t] = res[t] * W[i]; // 更新和wi相乘后的nxn矩阵
        }
    }
}

void work3() // nxn的矩阵和nxd的矩阵相乘
{
    for (int i = 1; i <= d; i++) // 枚举后一个矩阵的列数
    {
        // 对于这一列，要与前一个矩阵的每一行相乘
        for (int j = 1; j <= n; j++) // 枚举的行号
        {
            // 枚举这两行中每一个元素
            for (int k = 1; k <= n; k++)
            {
                // 取出nxn矩阵的数
                PII t = make_pair(j, k);
                // 把结果放到最终结果中
                ures[j][i] += res[t] * V[k][i];
            }
        }
    }
}

void rve() // 转置K矩阵
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            RK[j][i] = K[i][j];
        }
    }
}

int main()
{
    cin >> n >> d;

    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= d; k++)
            {
                if (i == 1)
                {
                    cin >> Q[j][k];
                }
                else if (i == 2)
                {
                    cin >> K[j][k];
                }
                else
                {
                    cin >> V[j][k];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> W[i];
    } // 读入一维向量

    rve(); // 转置k矩阵

    work1(); // 第一次乘法
    work2(); // 第二次乘法（向量W和nxn的矩阵相乘）
    work3(); // 第三次乘法（上一步的结果和V矩阵相乘（nxn的矩阵和nxd的矩阵相乘））
    // 最后得出的还是nxd的矩阵
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            cout << ures[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}