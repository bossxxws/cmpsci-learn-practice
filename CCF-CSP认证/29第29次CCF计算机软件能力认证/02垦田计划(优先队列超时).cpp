#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

int n, m, k; // k表示所需最小天数，m表示资源数量

const int N = 1e5 + 3;

// int t[N], c[N];

// vector<PII> tc;

priority_queue<PII> q;

int main()
{
    cin >> n >> m >> k;

    // q.push(make_pair(1, 2));

    // q.push(make_pair(5, 1));

    // q.push(make_pair(3, 4));

    // cout << q.top().first;

    for (int i = 1; i <= n; i++)
    {
        int t, c;

        cin >> t >> c;

        q.push(make_pair(t, c));
    }

    // 持续扫描，直到资源不足或者最大的耕地天数已经等于最小的限制（每次维护资源最大的值，大顶堆）
    while (q.top().first > k && q.top().second < m)
    {

        PII t = q.top();

        q.pop();

        PII s = q.top();

        int x = t.first - s.first; // 第一和第二相差的天数是x
        if (x == 0)                // 相差0天就减少1
        {
            int need = t.second;
            if (m >= need)
            {
                m -= need;
                t.first -= 1;
                q.push(t);
            }
        }
        else // 相差数天
        {
            int need = x * t.second; // 减少到和第二个一样需要这么多
            if (m >= need)
            {
                m -= need;
                t.first -= x;
                q.push(t);
            }
            else
            {
                int mt = m / t.second; // 最多减这么多天
                m -= mt * t.second;
                t.first -= mt;
                q.push(t);
            }
        }
    }

    cout << q.top().first;

    return 0;
}