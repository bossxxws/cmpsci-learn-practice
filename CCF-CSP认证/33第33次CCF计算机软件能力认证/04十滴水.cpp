#include <iostream>
#include <string>
#include <algorithm>
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
    //  �ұ�ˮ�δ�С��һ
    d_data[d_data[p].d_next].d_size++;
    // cout << d_data[d_data[p].d_next].d_size << endl;

    if (d_data[p].d_last != 0 && d_data[d_data[p].d_last].s)
        work(p - 1);
    if (d_data[d_data[p].d_next].s && d_data[p].d_next <= m)
        work(p + 1);
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
        d_data[i].d_last = d_data[i - 1].d_pos;
        d_data[i].d_next = d_data[i + 1].d_pos;
        // if(i==3)cout<<3333<<d_data[3].d_pos<<endl;
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
        d_data[p].d_size++;
        // cout << "��С" << d_data[p].d_size << endl;
        work(p);
        cout << res << endl;
    }

    return 0;
}
