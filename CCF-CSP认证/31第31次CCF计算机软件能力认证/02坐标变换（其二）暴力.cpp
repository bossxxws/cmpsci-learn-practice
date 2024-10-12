#include <iostream>
#include <cmath>

using namespace std;

int n, m;

const int N = 1e5 + 3;

int op1[N];

double op2[N];

int r1[N], r2[N];
double xi[N], yi[N];

int main()
{
    cin >> n >> m;
    // cout << sin(1.5) << endl;
    for (int i = 1; i <= n; i++)
    {
        cin >> op1[i] >> op2[i];

    } // 读入操作

    for (int i = 1; i <= m; i++)
    {
        cin >> r1[i] >> r2[i];

        cin >> xi[i] >> yi[i];
    } // 读入坐标和操作范围

    // 枚举每一个坐标
    for (int i = 1; i <= m; i++)
    {
        // 读取坐标对应的操作
        int l = r1[i];
        int r = r2[i];
        // cout << l << " " << r << endl;
        for (int j = l; j <= r; j++)
        {
            // 进行操作
            if (op1[j] == 1)
            {
                // 进行伸缩操作
                xi[i] *= op2[j];
                yi[i] *= op2[j];
            }
            else
            {
                // 进行旋转操作
                double t = op2[j];
                // cout << t << endl;
                double tx = xi[i];
                double ty = yi[i];
                xi[i] = tx * cos(t) - ty * sin(t);
                yi[i] = tx * sin(t) + ty * cos(t);
            }
        }
        printf("%.3f %.3f\n", xi[i], yi[i]);
    }
    return 0;
}