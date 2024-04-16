#include<bits/stdc++.h>

using namespace std;

const int N=100000+5;

int n,m,x;

int a[N];

int main()
{
	cin>>n>>m>>x;
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	while(m--)
	{
		bool f=false;
		
		int l,r;
		
		scanf("%d%d",&l,&r);
		
		for(int i=l;i<=r;i++)
		{
			
			if(f)break;

			for(int j=l+1;j<=r;j++)
			{
				if((a[i]^a[j])==x)
				{
					//cout<<a[i]<<" "<<a[j]<<" "<<1<<endl;
					f=true;
					break;
				}
			}

		}
		
		if(f)cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
	//cout<<x<<endl;
	//cout<<(1^2)<<endl;
	return 0;
}
