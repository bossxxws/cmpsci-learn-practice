#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N=1e5+5;

int n;

int a[N],b[N],c[N];
//��ǰ׺�ͺ����֪����¼ǰn������м��� 
int ma[N],mc[N];
int sa[N],sc[N];

int main()
{
	cin>>n;
	
	//����A 
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]); 
		ma[a[i]]++;
	}
	
	sa[0]=ma[0];//0�ĸ���Ҳ���ܺ���
	
	//����A��ǰ׺�� 
	//sa[i]�����С�ڵ���i�ĸ���
	for(int i=1;i<N;i++)sa[i]=sa[i-1]+ma[i];
	
	
	//����b
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	 
	//����c 
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
		mc[c[i]]++;
	}
	
	sc[0]=mc[0];//0�ĸ���Ҳ���ܺ���
	
	//����A��ǰ׺�� 
	//sc[i]�����С�ڵ���i�ĸ���
	for(int i=1;i<N;i++)sc[i]=sc[i-1]+mc[i];
	
	//ѯ��B
	LL res=0;
	for(int i=1;i<=n;i++)
	{
	    //cout<<sc[11];
		int t =b[i];
		//cout<<t<<endl;
		//cout<<sa[t-1];
		//cout<<sc[N-1]<<endl;
		res+=(LL)sa[t-1]*(sc[N-1]-sc[t]);
	}
	
	cout<<res;
	return 0;
} 
