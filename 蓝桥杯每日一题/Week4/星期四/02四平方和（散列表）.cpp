//四平方和
//模拟哈希表
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> PII;

const int N = 5e6 + 10;

int n;
int r[N * 2];//小技巧，避免pair，r[c^2+d^2]=c;可以推导出d

int main()
{
    cin >> n;

    memset(r, -1, sizeof r);

    for(int c = 0; c * c <= n; c++)
    {
        for(int d = c; c * c + d * d <= n; d++)
        {
            int t = c * c + d * d;
            if(r[t] == -1)
            {
                r[t] = c;
            }
        }
    }

    for(int a = 0; a * a <= n; a ++)
    {
        for(int b = a; a * a + b * b <= n; b++)
        {
            int t = n - a * a - b * b;
            int c = r[t];
            if(r[t] == -1) continue;
            int d = sqrt(t - c * c);
            printf("%d %d %d %d\n", a, b, c, d);
            return 0;
        }
    }
    return 0;
}


