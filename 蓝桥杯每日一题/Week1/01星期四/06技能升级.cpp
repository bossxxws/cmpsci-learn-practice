//ÿ�����ܶ���һ���Ȳ�����

//�����������ǰ�ÿ���Ȳ���������Ȼ�����ЩԪ��ȫ���ŵ�һ��������

//Ȼ������ȡǰM�������ܵõ������Ĺ���������һ��Ҳ�õ���̰�ĵ�˼�룩 

#include<bits/stdc++.h>

typedef long long LL;

const int N=2e5+10;

int n,m; 

using namespace std;

int a[N],b[N];

int q[N];

int hh=0; 

int main()
{
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		while(a[i]>=b[i])
		{
			q[hh++]=a[i];
			a[i]-=b[i];
		}
		if(a[i]>0)q[hh++]=a[i];
	} 
	
	sort(q,q+hh,greater<int>());
	
	//�����������
	//��ʼ���֣��������ʱ�������ֱ�ӱ���̰��ǰm�����÷�����
	
	LL maxs=0;
	
	for(int i=0;i<m;i++)
	{
		maxs+=q[i];
	}
	
	cout<<maxs<<endl;
	
	return 0;
} 
