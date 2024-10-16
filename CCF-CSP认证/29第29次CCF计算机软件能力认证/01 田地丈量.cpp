#include <iostream>

using namespace std;

typedef long long LL; // 最终的面积可能特别大

int n;
int a, b;

const int N = 103;

struct field
{
    /* data */
    int x1, y1, x2, y2; // 田地的四个角
};

field fld[N];

LL res;

int main()
{
    cin >> n >> a >> b;

    for (int i = 1; i <= n; i++) // n块田地的输入
    {
        cin >> fld[i].x1 >> fld[i].y1 >> fld[i].x2 >> fld[i].y2; // 读入第i个田地的信息

        // 由于田地a,b均大于0，所以说不符合条件的田地可以修改便于后续操作
        if (fld[i].x1 < 0)
            fld[i].x1 = 0;
        if (fld[i].y1 < 0)
            fld[i].y1 = 0;
        if (fld[i].x2 < 0)
            fld[i].x2 = 0;
        if (fld[i].y2 < 0)
            fld[i].y2 = 0;
    }

    for (int i = 1; i <= n; i++) // 枚举每一块田地
    {
        if (fld[i].x1 >= a || fld[i].y1 >= b)
        {
            continue;
        }

        if (fld[i].x2 > a)
        {
            fld[i].x2 = a;
        }

        if (fld[i].y2 > b)
        {
            fld[i].y2 = b;
        }

        res += (fld[i].x2 - fld[i].x1) * (fld[i].y2 - fld[i].y1);
    }

    cout << res;

    return 0;
}