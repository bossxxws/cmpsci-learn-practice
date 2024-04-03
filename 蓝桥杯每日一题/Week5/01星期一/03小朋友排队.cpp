#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10;

//对于每个小朋友，交换的次数等于后面的比他矮的加上前面的比他高的 
#define x first
#define y second 

typedef long long LL;

typedef pair<int,int> PII;

PII node[N];//身高、编号 

PII tmp[N];

int res[N];//用来存储每个小朋友的不高兴值的项数 

void merge(int l,int r)
{
	if(l>=r)return ;
	int mid=l+r>>1;
	merge(l,mid);merge(mid+1,r);
	int k=0,i=l,j=mid+1;
	while(i<=mid && j<=r)
	{
		if(node[i]<=node[j])//对于i来说，j前面的前高都比i小，j前面的数都和i交换过 
		{
			res[node[i].y]+=j-(mid+1);
			tmp[k++]=node[i++];
		}
		else//对于j来说，i以及i后面的数都比他大 
		{
			res[node[j].y]+=mid-i+1;
			tmp[k++]=node[j++];
		}
	}
	while(i<=mid)
	{
	    res[node[i].y]+=j-(mid+1);
	    tmp[k++]=node[i++];//mid后面j前面的小朋友的身高都比i小

	}
	while(j<=r)
	{
	    tmp[k++]=node[j++];
	}
	for(int i=l,j=0;i<=r;i++,j++)
	{
		node[i]=tmp[j];
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		node[i].x=a;
		node[i].y=i;
	}
	
	merge(1,n);
	
	LL sum=0;
	for(int i=1;i<=n;i++)
	{
		int c=res[i];//an=(n-1)d+a1
		//cout<<res[i];
		int a=c;
		sum+=(LL)(a+1)*c/2;
	}
	cout<<sum;
	return 0;
}
