#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int n,k;
int a[N],b[N];
//int method[N];

//typedef long long LL;


bool check(int mid)
{
	int x=0;
	for(int i=0;i<n;i++)
	{
		x+=(a[i]/mid)*(b[i]/mid); 
	}
	if(x>=k)return true;
	else return false;		
}

int main()
{
	cin>>n>>k;
	
	//�����ɿ����ĳ��� 
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
	}
	
	//6*5->6 * 2*2  -> 2* 3*3 ->1* 4*4
	
	//�ҹ��ɷ��ֳ��Ϳ�ֱ���Է���ı߳�������˾��ܵõ�����
	
	/*
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<a[i] && j<b[i];j++)
		{
			int x=a[i]/j;
			int y=b[i]/j;
			m[j]+=x*y;//��˼��j�鷽���Ŀ��� 
		}
	}
	*/
	
	//sort(method,method+n);//����ѡ�����ı߳� 
	
	int l=1,r=1e5+5;
	
	while(l<r)
	{
		int mid = l+r>>1;
		if(check(mid))l = mid+1;
		else r = mid;										
	}
	 
	cout<<r-1<<endl;
	return 0;
}
