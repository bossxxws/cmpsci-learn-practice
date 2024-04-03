#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10;

//����ÿ��С���ѣ������Ĵ������ں���ı������ļ���ǰ��ı����ߵ� 
#define x first
#define y second 

typedef long long LL;

typedef pair<int,int> PII;

PII node[N];//��ߡ���� 

PII tmp[N];

int res[N];//�����洢ÿ��С���ѵĲ�����ֵ������ 

void merge(int l,int r)
{
	if(l>=r)return ;
	int mid=l+r>>1;
	merge(l,mid);merge(mid+1,r);
	int k=0,i=l,j=mid+1;
	while(i<=mid && j<=r)
	{
		if(node[i]<=node[j])//����i��˵��jǰ���ǰ�߶���iС��jǰ���������i������ 
		{
			res[node[i].y]+=j-(mid+1);
			tmp[k++]=node[i++];
		}
		else//����j��˵��i�Լ�i��������������� 
		{
			res[node[j].y]+=mid-i+1;
			tmp[k++]=node[j++];
		}
	}
	while(i<=mid)
	{
	    res[node[i].y]+=j-(mid+1);
	    tmp[k++]=node[i++];//mid����jǰ���С���ѵ���߶���iС

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
