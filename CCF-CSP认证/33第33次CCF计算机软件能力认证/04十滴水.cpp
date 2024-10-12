#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int N = 1e6;

struct drop // ��������ˮ�Σ�������3e5��ˮ��
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
    // û�б�ը�����
    if (d_data[p].d_size < 5)
    {
        return;
    }
    // ��ը�����
    res--;
    d_data[p].s = false;
    // cout << res << endl;
    // ɾ�����ˮ��
    d_data[d_data[p].d_last].d_next = d_data[p].d_next;
    d_data[d_data[p].d_next].d_last = d_data[p].d_last;
    // ���ˮ�δ�С��һ
    d_data[d_data[p].d_last].d_size++;
    // cout << p<<" "<<d_data[d_data[p].d_next].d_pos << endl;
    // cout<<d_data[3].d_next<<endl;
    // �ұ�ˮ�δ�С��һ
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
    // ����λ�ö�ˮ�ν�������
    sort(d_data + 1, d_data + 1 + m, cmp);
    // ��ʼ����ϣ���������Ľ���
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
        // cout << "��С" << d_data[p].d_size << endl;
        work(tar);
        cout << res << endl;
    }

    return 0;
}
