#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

#define x first
#define y second

//1 2 6 9

const int N=1e5+5;


int a[N];

int pos;

LL res;

int main()
{
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	
	sort(a,a+n);//��С�������� 
	
	if(n%2)//����
	{
		int t=n/2; 
		pos=a[t];//ѡ���м�ĵ�����Ϊ�ֿ� 
	} 
	else
	{
		int t=n/2;
		int k=t-1;//ȡ�����ֿ���е�
		pos=(a[t]+a[k])/2;	
	} 
	
	for(int i=0;i<n;i++)
	{
		res+=abs(a[i]-pos);
	}
	cout<<res;
	return 0;
}
