#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second

int m;
const int N=1e5+3;


typedef pair<int,int> PII;

PII d[N];

int s0[N],s1[N];

bool cmp(PII a,PII b)
{
	return a.x<b.x;
}

int main()
{
	cin>>m;
	
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&d[i].x,&d[i].y);
	}
	
	sort(d+1,d+1+m,cmp);
	
//	for(int i=1;i<=m;i++)
//	{
//		cout<<d[i].x<<" ddd "<<d[i].y<<endl;
//	}
//	
	for(int i=1;i<=m;i++)//��¼ͨ���Ͳ�ͨ����ǰ׺�� 
	{
		s0[i]+=s0[i-1]+(d[i].y==0);//ǰi���������ǰ׺�� 
		s1[i]+=s1[i-1]+(d[i].y==1);//ǰi�������ǰ׺�� 
//		cout<<s0[i]<<" "<<s1[i]<<endl;
	}
	
	//��ʼѰ��res
	int res=0,maxi=0,idx=0;
	for(int i=1;i<=m;i++)
	{
		int j=i;
		int t=s0[i-1]+(s1[m]-s1[i-1]);//Ԥ��׼ȷ�ĸ���
//		cout<<"�� "<<i<<" �Σ� "<<t<<endl;
		if(t>=maxi)
		{
			res=d[i].x;
			maxi=t;
		} 
		while(j+1<=m && d[j+1].x==d[i].x)j++;
		i=j;
	} 
//	cout<<res<<" maxi: "<<maxi;
	cout<<res;
	return 0;
} 
