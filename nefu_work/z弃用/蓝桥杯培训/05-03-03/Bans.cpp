#include <bits/stdc++.h>

using namespace std;

typedef long long LL; 

unordered_map <LL, LL> m;

LL dfs(LL x)
{
    if(m.count(x)) return m[x];
    if(x == 1) return 0;
    if(x & 1)
        return m[x] = 1 + dfs(3 * x + 1);
    else
        return m[x] = 1 + dfs(x / 2);
}

int main()
{
    LL n, m;
    cin >> n >> m;
    
    LL maxn = 0, res = 0;
    for(int i = n; i <= m; ++ i)
	{
        LL ans = dfs(i);
        if(ans > maxn)
		{
            maxn = ans;
            res = i;
        }
    }
    cout << res << endl;
    return 0;
}
