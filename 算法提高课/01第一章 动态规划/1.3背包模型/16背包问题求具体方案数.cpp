#include <iostream>

using namespace std;

const int N = 1010;

int n, m;
int w[N], v[N];
int f[N][N];
int path[N], cnt;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i) cin >> v[i] >> w[i];
    //����һ�������� ����DP ��Ȼ��� Ŀ��״̬ ���ƻ� ��ʼ״̬ ������ ת��·�� ����
    //Ϊ�˱�֤�ֵ�����С������Ҫ����dp������ÿ�β�������ѡ���С����Ʒ
    for (int i = n; i >= 1; -- i)
    {
        for (int j = 0; j <= m; ++ j)
        {
            f[i][j] = f[i + 1][j];
            if (j >= v[i]) f[i][j] = max(f[i][j], f[i + 1][j - v[i]] + w[i]);
        }
    }
    for (int i = 1, j = m; i <= n; ++ i)
    {
        if (j >= v[i] && f[i][j] == f[i + 1][j - v[i]] + w[i])
        {
            path[cnt ++ ] = i;
            j -= v[i];
        }
    }
    for (int i = 0; i < cnt; ++ i) cout << path[i] << " ";
    cout << endl;
    return 0;
}
