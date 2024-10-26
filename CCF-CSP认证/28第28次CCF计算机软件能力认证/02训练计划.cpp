#include <iostream>

using namespace std;

int n, m;

const int N = 365 + 5;

int p[N], t[N], res[N];

int preadd(int x)
{
    if (!p[x])
        return t[x];
    else
    {
        return t[x] + preadd(p[x]);
    }
}

int check(int x) // 返回每个科目最早开始的时间
{
    if (p[x] == 0)
    {
        return 1;
    }
    else // 如果有前置的，需要加上前置的完成时间
    {
        return 1 + preadd(x) - t[x];
    }
}

void work()
{
    for (int i = n; i >= 1; i--)
    {
        if (!res[i])
            res[i] = t[i];
        if (p[i])
        {
            // 如果有前面的依赖，那么要么现在的时间加到前面的依赖上
            // 面对一个课程有多个依赖的情况下，根节点的累加时间取最大值
            // 遍历到res[i]的时候，已经把res[i]更新完毕，然后用res[i]+t[p[i]]更新最大所需时间：res[p[i]]
            res[p[i]] = max(t[p[i]] + res[i], res[p[i]]);
        }
    }
}

int main()
{
    cin >> m >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
    }

    // cout << check(5)<<" "<<t[5];

    bool flag = true;
    for (int i = 1; i <= n; i++)
    {
        int ti = check(i);
        cout << ti << " ";
        if (preadd(i) > m)
            flag = false;
    }

    if (flag) // 如何可以完成，那么接下来计算最晚开始天数：有后续依赖的必须计算加上后续依赖的天数
    {
        work();
        cout << endl;
        for (int i = 1; i <= n; i++)
        {
            // cout<<t[i]<<endl;
            cout << m - res[i] + 1 << " ";
        }
    }

    return 0;
}