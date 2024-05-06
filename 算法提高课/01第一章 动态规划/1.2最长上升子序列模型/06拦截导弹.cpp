#include<bits/stdc++.h>

using namespace std;

const int maxn = 1005;
int n, a[maxn];
int f[maxn], g[maxn];

//每次都拦截最长下降子序列
//如果拦截完还有，就要把拦截过的去掉
//求的是第一次最多拦截的导弹数
//还有最少需要配备多少个系统才能拦截所有导弹
 

//	题目的第二问，对于第i号导弹，要么选择末尾导弹高度最小的拦截系统，要么新创一个拦截系统，用一个数字即每套拦截系统此时所拦截的最后一个导弹高度，来表示该系统。
//	这样就得到了一个数组，数组最终长度就是所需最少拦截系统数目。


int main()
{
    while(cin >> a[n]) n ++;
    int ans = 0, cnt = 0;
    for(int i = 0; i < n; i ++)
    {
        f[i] = 1;
        for(int j = 0; j < i; j ++)
        {
            if(a[i] <= a[j]) f[i] = max(f[i], f[j] + 1);
        }
        ans = max(ans, f[i]);
        //数组g的每个元素代表一套导弹拦截系统的拦截序列
        //g[i]表示此时第i套导弹拦截系统所拦截的最后一个导弹的高度
        int p = lower_bound(g, g+cnt, a[i]) - g;
        if(p == cnt) g[cnt ++] = a[i];  //a[i]开创一套新拦截系统    
        else g[p] = a[i];               //a[i]成为第p套拦截系统最后一个导弹高度
    }
    cout << ans << endl;
    cout << cnt << endl;
    return 0;
}

