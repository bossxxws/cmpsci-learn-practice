#include <iostream>

using namespace std;

typedef long long LL;

const int K = 203;

int N, n;

int a[K];

int main()
{
    cin >> n >> N;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    LL sum = 0;
    int t;
    // 从0开始枚举，枚举到第N个数
    // 求出对应的f值
    // 下标为j，连续个数为cnt
    for (int i = 0, j = 0; i <= N - 1; i++)
    {
        if (j > n)
        {
            sum += (j - 1) * (N - t);
            break;
        }
        int cnt = 0;
        while (j <= n && i < a[j + 1])
        {
            cnt++;
            i++;
            t = i;
        }
        // cout << j << endl;
        // cout << cnt << endl;
        sum += j * cnt;
        j++;
        i--;
    }

    cout << sum;
    return 0;
}