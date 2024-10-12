#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int N = 1e6;

struct drop // 用来储存水滴（不超过3e5滴水）
{
    int d_pos;
    int d_size;
    int d_last;
    int d_next;
    bool s = true;
} d_data[N];

bool cmp(drop a, drop b)
{
    return a.d_pos < b.d_pos;
}

int c, m, n;
int res;

unordered_map<int, int> mp;

void work(int p)
{
    // 没有爆炸的情况
    if (d_data[p].d_size < 5)
    {
        return;
    }
    // 爆炸的情况
    res--;
    d_data[p].s = false;
    // cout << res << endl;
    // 删除这个水滴
    d_data[d_data[p].d_last].d_next = d_data[p].d_next;
    d_data[d_data[p].d_next].d_last = d_data[p].d_last;
    // 左边水滴大小加一
    d_data[d_data[p].d_last].d_size++;
    // cout << p<<" "<<d_data[d_data[p].d_next].d_pos << endl;
    // cout<<d_data[3].d_next<<endl;
    // 右边水滴大小加一
    d_data[d_data[p].d_next].d_size++;
    // cout << d_data[d_data[p].d_next].d_size << endl;

    if (d_data[p].d_last > 0 && d_data[d_data[p].d_last].s)
        work(d_data[p].d_last);
    if (d_data[d_data[p].d_next].s && d_data[p].d_next <= m)
        work(d_data[p].d_next);
    return;
}

int main()
{

    scanf("%d%d%d", &c, &m, &n);
    for (int i = 1; i <= m; i++)
    {
        int x, w;
        cin >> x >> w;
        d_data[i].d_pos = x;
        d_data[i].d_size = w;
    }
    // 根据位置对水滴进行排序
    sort(d_data + 1, d_data + 1 + m, cmp);
    // 初始化完毕，进行链表的建立
    // cout<<m<<endl;
    for (int i = 1; i <= m; i++)
    {
        d_data[i].d_last = i - 1;
        d_data[i].d_next = i + 1;
        // if(i==3)cout<<3333<<d_data[3].d_pos<<endl;
        mp[d_data[i].d_pos] = i;
    }
    res = m;
    // for (int i = 1; i <= m; i++)
    // {
    //     cout << d_data[i].d_pos << endl;
    // }
    while (n--) // to operate !!
    {
        int p;
        cin >> p;
        // cout<<d_data[p].d_size<<endl;
        int tar = mp[p];
        d_data[tar].d_size++;
        // cout << "大小" << d_data[p].d_size << endl;
        work(tar);
        cout << res << endl;
    }

    return 0;
}
