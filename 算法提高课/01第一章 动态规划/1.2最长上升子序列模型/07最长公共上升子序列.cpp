#include<bits/stdc++.h>

using namespace std;

const int N=3000;

int n; 

int a[N];

int b[N];

int f[N][N];

//f[i][j]��������a[1 ~ i]��b[1 ~ j]����b[j]��β�Ĺ������������еļ��ϣ�
//f[i][j]��ֵ���ڸü��ϵ��������г��ȵ����ֵ��

int main()
{

    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &b[i]);
    
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			
			f[i][j]=f[i-1][j];
			
			if(a[i]==b[j])
			{
				int maxv=1;
				
				for(int k=1;k<j;k++)if(b[j]>b[k])maxv=max(maxv,f[i-1][k]+1);	
				f[i][j]=max(f[i][j],maxv);		
			}	
			
		}
	}
	int res=-1;
	
	
	for(int i=1;i<=n;i++)res=max(res,f[n][i]);
	
	cout<<res;
	
	return 0;
}
