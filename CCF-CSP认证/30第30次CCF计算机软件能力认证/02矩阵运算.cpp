#include <iostream>

using namespace std;

const int N = 1e4;
const int D = 22;

int Q[N][D], K[N][D], V[N][D], RK[D][N];

int W[N];

int n, d;

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
    }

    rve();

        return 0;
}