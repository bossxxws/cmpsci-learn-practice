#include <iostream>

using namespace std;

typedef long long LL;

const int K = 1e5 + 3;

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
    a[n + 1] = N;
    // 按f[i]分段
    int d, cnt, f, g;
    int r = (N) / (n + 1);
    for (int i = 0; i <= n; i++)
    {
        f = i;
        // 按g分段
        for (int j = a[i]; j >= a[i] && j < a[i + 1]; j += d)
        {
            int g = j / r;
            int last = (g + 1) * r - 1;     // 最后一个维持g值的数的大小
            last = min(last, a[i + 1] - 1); // 这个数不能大于a[i+1]-1
            cnt = last - j + 1;
            sum += abs(f - g) * cnt;
            d = cnt;
        }
    }

    cout << sum;
    return 0;
}
