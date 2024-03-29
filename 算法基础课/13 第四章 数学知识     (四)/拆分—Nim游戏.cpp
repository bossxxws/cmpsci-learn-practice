#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int n;
int f[N];
unordered_set<int> S;

int sg(int x)
{
    if(f[x] != -1) return f[x];


    for(int i = 0 ; i < x ; i++)
        for(int j = 0 ; j <= i ; j++)//�涨j������i�������ظ�
            S.insert(sg(i) ^ sg(j));//�൱��һ�������ֳ����������棬��SG�������ۣ�������������SGֵ��
                                   //������Щ����SGֵ������

    for(int i = 0 ; ; i++)
        if(!S.count(i))
            return f[x] = i;
}

int main()
{
    memset(f , -1 , sizeof f);

    cin >> n;
    int res = 0;
    while(n--)
    {
        int x;
        cin >> x;
        res ^= sg(x);
    }

    if(res) puts("Yes");
    else puts("No");
    return 0;
}


