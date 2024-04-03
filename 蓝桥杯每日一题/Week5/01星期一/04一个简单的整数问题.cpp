#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int b[N]; 

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
	}
	
	for(int j=n;j>=0;j--)
	{
		b[j]=b[j]-b[j-1];
	}
	 
	while(m--)
	{
		char op[1];
		scanf("%s",&op);
		if(op[0]=='Q')
		{
		    //cout<<"yes";
			int x;
			scanf("%d",&x);
			for(int i=1;i<=x;i++)
			{
				b[i]=b[i]+b[i-1];
			}
			printf("%d\n",b[x]);
			for(int i=x;i>=0;i--)
			{
			    b[i]-=b[i-1];
			}
		}
		else if(op[0]=='C')
		{
		    int l,r,c;
		    scanf("%d%d%d",&l,&r,&c);
		    b[l]+=c;
		    b[r+1]-=c;
		}
	}
	return 0;
} 
