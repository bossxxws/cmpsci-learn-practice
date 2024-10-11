#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int N = 1e6;

struct drop // 用来储存水滴（不超过3e5滴水）
{
    int d_pos;
    int d_size;
    int d_last;
    int d_next;
} data[N];

bool cmp(drop a, drop b)
{
    return a.d_pos < b.d_pos;
}

int c, m, n;

void work(int p)
{
}

int main()
{

    scanf("%d%d%d", &c, &m, &n);
    for (int i = 1; i <= m; i++)
    {
        int x, w;
        cin >> x >> w;
        data[i].d_pos = x;
        data[i].d_size = w;
    }
    // 根据位置对水滴进行排序
    sort(data + 1, data + 1 + m, cmp);
    while (n--) // 进行操作
    {
        int p;
        cin >> p;
        work(p);
    }

    return 0;
}
