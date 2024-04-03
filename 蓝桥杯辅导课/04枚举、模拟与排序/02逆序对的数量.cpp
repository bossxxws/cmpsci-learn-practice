#include<bits/stdc++.h>

using namespace std;

int n;

const int N=1e5+5;

long long res;

int a[N];

int tmp[N];

void ms(int l,int r)
{
	if(l>=r)return ;
	long long  mid=(long long)l+r>>1;
	ms(l,mid),ms(mid+1,r);
	int i=l,j=mid+1,k=0;
	while(i<=mid && j<=r)
	{
		if(a[i]>a[j])
		{
            res+=(long long )mid-i+1;
			tmp[k++]=a[j++];
		}
		else
		{
			tmp[k++]=a[i++];
		}
	}
	while(i<=mid)
	{
		tmp[k++]=a[i++];
	}
	while(j<=r)
	{
		tmp[k++]=a[j++];
	}
	for(int i=l,j=0;j<k;j++,i++)
	{
		a[i]=tmp[j];
	}
}

int main()
{
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}

	ms(0,n-1);

	cout<<res;
	return 0;
} 
