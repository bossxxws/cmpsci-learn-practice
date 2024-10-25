#include <iostream>
#include <cmath>
using namespace std;

int n;

const int N = 1003;

double a[N];

int main()
{
    cin >> n;

    double tot = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        tot += a[i];
    }

    // 计算平均值

    double a_vg = tot / n;

    // 计算方差开根号

    double D = 0;
    for (int i = 1; i <= n; i++)
    {
        D += pow(a[i] - a_vg, 2);
    }
    D /= n;
    D = sqrt(D);
    for (int i = 1; i <= n; i++)
    {
        cout << (a[i] - a_vg) / D << endl;
    }

    return 0;
}