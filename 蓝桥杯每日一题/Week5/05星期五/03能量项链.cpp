#include <iostream>
#include <cstring>

using namespace std;

const int N = 110, M = N << 1;

int n, w[M], f[M][M];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i) scanf("%d", &w[i]), w[n + i] = w[i];
    
    memset(f, -0x3f, sizeof f); //������Բ��ó�ʼ������Ϊ�����ڸ�����״ֵ̬�����0������С��
    
	for (int len = 2; len <= n + 1; ++ len)
        for (int l = 1;l + len - 1 <= (n*2); ++ l)
		{
			int r=l+len-1;
            if (len == 2) f[l][r] = 0; //��ʼ����ʼ״̬
            else
            {
            	for (int k = l + 1; k < r; ++ k)
            	{
            		f[l][r] = max(f[l][r], f[l][k] + f[k][r] + w[l] * w[k] * w[r]);
				}
			}
		}

	int res = 0;
    
	for (int l = 1; l <= n; ++ l) res = max(res, f[l][l + n]);
    
	printf("%d\n", res);
    
	return 0;
}

