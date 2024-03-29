//四平方和
//二分
#include<bits/stdc++.h>

using namespace std;

const int N = 5e6 + 10;

struct Sum{
    int s, c, d;
    bool operator<(const Sum &t)const
    {
        if(s != t.s) return s < t.s;
        if(c != t.c) return c < t.c;
        return d < t.d;
    }
};

int n;
Sum record[N * 2];

int main()
{
    cin >> n;

    int k = 0;
    for(int c = 0; c * c <= n; c++)
    {
        for(int d = c; c * c + d * d <= n; d ++)
        {
            record[k++] = {c * c + d * d, c, d};
        }
    }

    sort(record, record + k);

    for(int a = 0; a * a <= n; a ++)
    {
        for(int b = a; a * a + b * b <= n; b++)
        {
            int t = n - a * a - b * b;

            int l = 0, r = k - 1;
            while(l < r)
            {
                int mid = l + r >> 1;
                if(record[mid].s >= t) r = mid;
                else l = mid + 1;
            }

            if(record[l].s == t)
            {
                printf("%d %d %d %d\n", a, b, record[l].c, record[l].d);
                return 0;
            }
        }
    }
    return 0;
}

