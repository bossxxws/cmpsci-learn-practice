#include<bits/stdc++.h>

using namespace std;

const int N=41;

int a[360];

int b[5];

int n,m;

int f[N][N][N][N];

int main()
{
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	
	for(int i=1;i<=m;i++)
	{
		int t;
		scanf("%d",&t);
		
		b[t]++;
		//cout<<b[t];
	}

	for(int b1=0;b1<=b[1];b1++)
		for(int b2=0;b2<=b[2];b2++)
			for(int b3=0;b3<=b[3];b3++)
				for(int b4=0;b4<=b[4];b4++)
				{
					f[b1][b2][b3][b4]=a[b1+2*b2+3*b3+4*b4+1];
				}


    
	for(int b1=0;b1<=b[1];b1++)
		for(int b2=0;b2<=b[2];b2++)
			for(int b3=0;b3<=b[3];b3++)
				for(int b4=0;b4<=b[4];b4++)
				{
					
					int t=a[b1+2*b2+3*b3+4*b4+1];
					
					auto &v=f[b1][b2][b3][b4];
					
					if(b1)v=max(v,f[b1-1][b2][b3][b4]+t);
					
					if(b2)v=max(v,f[b1][b2-1][b3][b4]+t);
					
					if(b3)v=max(v,f[b1][b2][b3-1][b4]+t);
					
					if(b4)v=max(v,f[b1][b2][b3][b4-1]+t);
					
				}
				
	cout<<f[b[1]][b[2]][b[3]][b[4]];
	return 0;
}
