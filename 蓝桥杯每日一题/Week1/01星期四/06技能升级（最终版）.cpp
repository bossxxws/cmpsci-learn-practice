//ÿ�����ܶ���һ���Ȳ�����

//�����������ǰ�ÿ���Ȳ���������Ȼ�����ЩԪ��ȫ���ŵ�һ��������

//Ȼ������ȡǰM�������ܵõ������Ĺ���������һ��Ҳ�õ���̰�ĵ�˼�룩 

#include<bits/stdc++.h>

typedef long long LL;

const int N=2e5+10;

int n,m; 

using namespace std;

int a[N],b[N];

bool check(LL mid)
{
	LL res=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]>=mid)res+=(a[i]-mid)/b[i]+1;//���ϵ�i���д��ڵ���mid�����ĸ���	
	}
	
	return res>=m;
}

int main()
{
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
	} 
	
	
	int l=0,r=1e6;
	
	while(l<r)
	{
		LL mid=l+r+1>>1;
		if(check(mid))l=mid;//check��mid����ʾ�����ڵ���mid�����ǲ���������m��
		//Ϊʲô�Ǵ��ڵ��ڣ���ΪmidҲ�п����Ǵ� 
		else r=mid-1;
	}
	
	LL res=0,cnt=0;
	
	for(int i=0;i<n;i++)
	{
		if(a[i]>=r)
		{
			LL c=(a[i]-r)/b[i]+1;
			LL end=a[i]-(c-1)*b[i];
			cnt+=c;
			res+=(a[i]+end)*c/2;
		}	
	} 
	//cout<<r<<endl;
	//cout<<res<<endl;
	
	cout<<res-(cnt-m)*r<<endl;
	
	return 0;
} 
