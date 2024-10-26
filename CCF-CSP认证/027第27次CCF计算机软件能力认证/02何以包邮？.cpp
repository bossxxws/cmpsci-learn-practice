#include <iostream>
#include <algorithm>
using namespace std;

int n, x;

const int N = 33;

int a[N];

int main()
{
    cin >> n >> x;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n + 1);
    // 前缀和
    for (int i = 1; i <= n; i++)
    {
        a[i] += a[i - 1];
    }

    int total = a[n], res = a[n];

    // for(int i=1;i<=n;i++)
    // {
    //     cout<<a[i]<<endl;
    // }
    // 双指针
    for (int i = 0; i <= n; i++)
    {
        int r = n, l = i;
        // cout<<total<<" "<<res<<endl;
        while (total - a[n] + a[r] - a[l] >= x)
        {

            int t = total - a[n] + a[r] - a[l];
            // if(i==2)cout<<t<<endl;
            // cout<<t<<endl;
            res = min(t, res);
            r--;
        }
    }

    cout << res;

    return 0;
}