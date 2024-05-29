#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1010;
int f[N][N];
int v[N],w[N];
int n,m;
int main()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
        cin >> v[i] >> w[i];
    for(int i = n ; i >= 1 ; i --)
    {
        for(int j = 0 ; j <= m ; j++)
        {
            f[i][j] = f[i + 1][j];
            if(j >= v[i])
                f[i][j] = max(f[i][j],f[i + 1][j - v[i]] + w[i]);
        }
    }
    int cur_v = m;
    for(int i = 1 ; i <= n ; i++)
    {   //��������һ��Ԫ�أ�����һ�£���ֹԽ�缴��
        if(i == n && cur_v >= v[i])
        {
            printf("%d ",i);
            break;
        }
        if(cur_v <= 0)
            break;
        //�ж��±��Ƿ�Խ��
        if(cur_v - v[i]>=0 && f[i][cur_v] == f[i + 1][cur_v - v[i]] + w[i]){
            printf("%d ",i);
            cur_v = cur_v - v[i];//ѡ�˵�i����Ʒ��ʣ��������Ҫ��С��
        }
    }
    return 0;
}

