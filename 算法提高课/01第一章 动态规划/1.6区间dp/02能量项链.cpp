#include<bits/stdc++.h>

using namespace std;

const int N=203;

int w[N];//�������� 

int f[N][N];//����i��j���ͷŵ�������� 

int n; 

int main()
{
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
		w[i+n]=w[i];
	}
	
	for(int len=2;len<=n+1;len++)//ö�����䳤�� 
	{
		for(int l=1;l+len-1<=2*n;l++)//ö����˵� 
		{
			int r=l+len-1;
			
			if(len==2)f[l][r]=0;
			else
			{
				for(int k=l+1;k<r;k++)
				{
					f[l][r]=max(f[l][r],f[l][k]+f[k][r]+w[l]*w[k]*w[r]);
				}	
			} 
		}
	}
	
    int res = 0;
    
	for (int l = 1; l <= n; ++ l) res = max(res, f[l][l + n]);
    
	printf("%d\n", res);
	
	return 0;
}
