#include <iostream>

using namespace std;

int n;
int m;

const int N = 23;

int a[N], c[N]; // c[n]就是a[n]的前缀积数组

int main()
{
    cin >> n >> m;
    c[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        c[i] = c[i - 1] * a[i];
    }

    int lst = 0; // 记录上一个%出来的数据

    for (int i = 1; i <= n; i++)
    {
        int tmp = m % c[i];
        tmp -= lst;
        lst = m % c[i];
        tmp /= c[i - 1];
        cout << tmp << " ";
    }

    return 0;
}