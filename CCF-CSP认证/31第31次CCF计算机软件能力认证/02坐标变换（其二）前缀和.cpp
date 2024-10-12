#include <iostream>
#include <cmath>

using namespace std;

int n, m;

const int N = 1e5 + 3;

double s1[N];

double s2[N];

int r1[N], r2[N];
double xi[N], yi[N];

int main()
{
    s1[0] = 1;
    s2[0] = 0;
    cin >> n >> m;
    // cout << sin(1.5) << endl;
    for (int i = 1; i <= n; i++)
    {

        int a;
        double xx;
        cin >> a >> xx;
        if (a == 1)
        {
            s1[i] = xx;
            s1[i] *= s1[i - 1];
            s2[i] = s2[i - 1];
        }
        else
        {
            s2[i] = xx;
            s2[i] += s2[i - 1];
            s1[i] = s1[i - 1];
        } // 前缀和操作

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

        // 进行操作
        double kkk = s1[r] / s1[l - 1];
        double ttt = s2[r] - s2[l - 1];

        xi[i] *= kkk;
        yi[i] *= kkk;

        double tx = xi[i];
        double ty = yi[i];
        xi[i] = tx * cos(ttt) - ty * sin(ttt);
        yi[i] = tx * sin(ttt) + ty * cos(ttt);
        printf("%.3f %.3f\n", xi[i], yi[i]);
    }

    return 0;
}