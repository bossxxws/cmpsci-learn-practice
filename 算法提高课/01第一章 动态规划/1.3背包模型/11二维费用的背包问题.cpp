#include <bits/stdc++.h>
// Ҳ����01�������⣬ֻ�����ж�������ά�ȣ�һ����ֵά��
using namespace std;

// v��m������
// Ŀ�꣺ʹ��w���

// f[i][j][k]��ʾѡǰi����Ʒ�����������j������������k�ļ�ֵ��״̬�ļ���
// ���ԣ����ֵ

const int N = 1003;

const int M = 103;

int v[N], m[N]; // ���������

int w[N]; // ��ֵ

int f[N][M][M];

int main()
{
    int n, V, M;
    cin >> n >> V >> M;

    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &v[i], &m[i], &w[i]);
    }

    for (int i = 1; i <= n; i++) // ö�ٵ�i����Ʒ
    {
        for (int j = 0; j <= V; j++)
        {
            for (int k = 0; k <= M; k++)
            {
                f[i][j][k] = max(f[i][j][k], f[i - 1][j][k]);
                if (j >= v[i] && k >= m[i])
                    f[i][j][k] = max(f[i][j][k], f[i - 1][j - v[i]][k - m[i]] + w[i]);
            }
        }
    }
    cout << f[n][V][M];
    return 0;
}
