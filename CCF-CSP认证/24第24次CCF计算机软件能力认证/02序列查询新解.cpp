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
    // ��f[i]�ֶ�
    int d, cnt, f, g;
    int r = (N) / (n + 1);
    for (int i = 0; i <= n; i++)
    {
        f = i;
        // ��g�ֶ�
        for (int j = a[i]; j >= a[i] && j < a[i + 1]; j += d)
        {
            int g = j / r;
            int last = (g + 1) * r - 1;     // ���һ��ά��gֵ�����Ĵ�С
            last = min(last, a[i + 1] - 1); // ��������ܴ���a[i+1]-1
            cnt = last - j + 1;
            sum += abs(f - g) * cnt;
            d = cnt;
        }
    }

    cout << sum;
    return 0;
}
