#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;

const int MOD=99999997;

typedef long long LL;

int n;
int a[N],b[N],c[N],tmp[N];

int p[N]; //��ɢ����Ľ������p������ 

//Ҫһһ��Ӧ�������þ�����С 

//��ɢ�� 
void work(int a[])
{
	for(int i=1;i<=n;i++)p[i]=i; 
	
	sort(p+1,p+n+1,[&](int x,int y)
	{
		{
			return a[x]<a[y];
		}
	});
	
	for(int i=1;i<=n;i++)a[p[i]]=i;//a�е�iС������ֵΪi������Ϊp��i������a�и�ֵΪi��ʾ��iС����a�еڼ��� 
}

int merge(int l,int r)
{
	if(r<=l)return 0;
	int mid=(l+r)>>1;
	int k=0,i=l,j=r,res=0;
	while(i<=mid && j<=r)
	{
		if(b[j]>=b[i])tmp[k++]=b[i++];
		else
		{
			res+=mid-i+1;
			tmp[k++]=b[j++];
		}
	}
	while(i<=mid)
	{
		tmp[k++]=b[i++];
	}
	while(j<=r)
	{
		tmp[k++]=b[j++];
	}
	for(int i=l,j=0;i<=n;i++,j++)
	{
		b[i++]=tmp[j++];
	}
} 

int main()
{
	cin>>n;
    
    for(int i=1;i<=n;i++)cin>>a[i];
    
    for(int i=1;i<=n;i++)cin>>b[i];
    
    LL res=0;
    
    //��λ��һһ��Ӧ����
	
	work(a);work(b);
	//work��ɢ��֮��a��b���ǰ�������ģ�������Ŷ���1-n 
	//�����ǰ���ԭ�������дӴ�С���������е�
	//������͵Ļ���������3����ô3������ǰ�� 
	
	for(int i=1;i<=n;i++)c[a[i]]=i; //�ѵ�����λ�õ�ӳ��ͳһ���1 
	 
	
	for(int i=1;i<=n;i++)b[i]=c[b[i]];//��b����ӳ������һ�� 
    
    res=merge(0,n-1);
    
    cout<<res;
    
    return 0;
}
