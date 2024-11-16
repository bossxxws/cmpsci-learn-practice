#include <iostream>
#include <algorithm>
using namespace std;

const int N = 500004, M = 10004;
int n, a[N], cnt[M];

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    a[0] = a[n + 1] = 0; // �߽�
    n = unique(a, a + 2 + n) - a;
    // ȥ�غ󲻴������ڴ���ȵ����
    for(int i = 1; i < n; i++)
    {
        if(a[i - 1] < a[i] && a[i] > a[i + 1]) // ͹��
            cnt[a[i]]++;
        else if(a[i - 1] > a[i] && a[i] < a[i + 1]) // ����
            cnt[a[i]]--;
    }

    int res = 0, sum = 0;
    for(int i = M-1; i; i--)
    {
        sum += cnt[i];
        res = max(res, sum);
    }
    printf("%d\n", res);
    return 0;
}

