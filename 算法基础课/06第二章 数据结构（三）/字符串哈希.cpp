#include<bits/stdc++.h>
using namespace std;

int n,m;

typedef unsigned long long  ULL;

const int N=100010,P=131;//P����p���Ƶı�� ��131���ƣ� 

char str[N];
ULL h[N],p[N];

//����ӳ���0 
//�ٶ������ڳ�ͻ�����
//��pȡ131��1331��ʱ���������Ǿ���ֵ����qȡ��2��64�η������Լٶ�������ֳ�ͻ��99.99%������²����ͻ��
//h[lr]=h[r]-h[l]*P**(l-r+1),Ϊl��r֮��Ĺ�ϣֵ 

ULL get(int l,int r)
{
	return h[r]-h[l-1]*p[r-l+1];
}

int main()
{
	cin>>n>>m>>str+1;
	//Ԥ����
	p[0]=1;
	for(int i=1;i<=n;i++)p[i]=p[i-1]*P; //ÿ��λ�õ�Ȩ������� ��Ϊp�Ĵη� 
	for(int i=1;i<=n;i++)h[i]=h[i-1]*P + str[i];
	while(m--)
	{
		int l1,r1,l2,r2;
		cin>>l1>>r1>>l2>>r2;
		if (get(l1,r1)==get(l2,r2))cout<<"Yes"<<endl;
		else cout<<"No"<<endl; 
		
	}	
	
	return 0;
}
