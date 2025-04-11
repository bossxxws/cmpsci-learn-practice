#include <iostream>
#include <set>

using namespace std;

int n, L, S;

const int N = 1003; // 1000个节点有树
const int SN = 53;

int s[SN][SN];

set<pair<int, int>> se;

int cnt;

void work(int x, int y)
{
    for (int i = 0; i <= S; i++)
    {
        for (int j = 0; j <= S; j++)
        {
            if (x + i > L || y + i > L)
            {
                return;
            }
            if (s[i][j] && !(se.find(make_pair(x + i, y + j)) != se.end())) // s有，se无
            {
                return;
            }
            else if (!s[i][j] && (se.find(make_pair(x + i, y + j)) != se.end())) // se有，s无
            {
                return;
            }
        }
    }
    cnt++;
    return;
}

int main()
{

    cin >> n >> L >> S;

    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        se.insert(make_pair(x, y));
    } /// 读入可疑的点

    for (int i = S; i >= 0; i--)
    {
        for (int j = 0; j <= S; j++)
        {
            // scanf("%d", &s[i]);
            cin >> s[i][j];
            // cout << s[i][j] << " ";
        }
        // cout << endl;
    } // 读入S藏宝图

    // 依次枚举可疑点!
    for (auto t : se)
    {
        int x = t.first;
        int y = t.second;
        // cout << x << " " << y << endl;
        work(x, y);
    }
    cout << cnt;
    return 0;
}