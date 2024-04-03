#include<bits/stdc++.h>

//�������ǣ������λ�������������ʾΪ1������<=x�����ǵ��������Ա�ʾΪǰ׺�� 
//���������������ѯ�ʣ����ҿ���ת��Ϊ����ͣ������뵽��״���� 
//ע���ǰ�x��y�������ģ�ÿ�β��붼��ԭʼ�ǿյ����Ϸ���������˵���԰��������ǵĵȼ� 
using namespace std;

const int N=15000+10,M=32000+10;

int n;
 
int tr[M];

int level[N];

int lowbit(int x)
{
	return x&-x;
}

int query(int x)
{
	int res=0;
	for(int i=x;i;i-=lowbit(i))
	{
		res+=tr[i];
	}
	return res;
}

void add(int x,int v)
{
	for(int i=x;i<=M;i+=lowbit(i))
	{
		tr[i]+=v;
	}
}

int main()
{
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x++;//��״�����Ǵ�1��ʼ�� 
		int t=query(x);
		level[t]++;
		add(x,1);
	}
	
	for(int i=0;i<n;i++)
	{
		printf("%d\n",level[i]);
	}	
	return 0;
}
