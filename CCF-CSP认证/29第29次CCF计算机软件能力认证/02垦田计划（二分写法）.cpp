#include <iostream>

using namespace std;

// 耗时越少所需资源越多,符合单调性，可以二分搜索

int n, m, k;

const int N = 1e5 + 5;

int t[N], c[N];

bool check(int x)
{
    int tmp = m;
    // 总共有m资源，把每一块地都减小为x天，看资源是否够用
    for (int i = 1; i <= n; i++) // 枚举n块地
    {
        if (t[i] > x)
        {
            int kx = t[i] - x;
            tmp -= kx * c[i];
            if (tmp < 0)
                return false;
        }
        // cout<<t[i]<<" "<<tmp<<endl;
    }
    return true;
}

int main()
{
    cin >> n >> m >> k;

    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i] >> c[i];
        mx = max(t[i], mx);
    }

    int l = k, r = mx;

    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid; // 要求最小值，往左缩小
        else
            l = mid + 1;
        // 如果有时候要用l=mid，那就是r=mid-1，并且mid=l+r+1>>1
        // cout<<mid<<endl;
    }

    cout << l;
    return 0;
}