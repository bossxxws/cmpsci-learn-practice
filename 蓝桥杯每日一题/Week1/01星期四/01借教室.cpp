//�뵽һ��������Ӽ��͸��뵽���
//�������һ���ӭ������������ô��һ�������ж����������
//���Կ��Է�Ϊ����
//���Բ�ִ��������ݺ���ö������� 

#include<bits/stdc++.h>

using namespace std;

const int N=1e6+10;

int n,m;//�����Ͷ�������
int rooms[N]; //ÿ��ɽ���ҵ�����
//�洢ѯ�� 
int d[N],s[N],t[N];
//�������
long long  b[N]; 

bool check(int mid)
{
	memset(b,0,sizeof b);
	
	//���������� 
	for(int i=1;i<=mid;i++)
	{
		b[s[i]]  +=d[i];
		b[t[i]+1]-=d[i];//�൱�� 1��m������ ��ÿ�����������䶼��ȥ d��i��������Ҫ��Ľ������� 
	}
	
	//��ǰ׺��
	for(int i=1;i<=n;i++)
	{
		b[i]=b[i]+b[i-1];
		//cout<<b[i]<<endl;
		if(b[i]>rooms[i])return false;//���ĳһ���Ĵ��ڵ���Ľ�����������false 
	} 
	//cout<<"yes"<<endl;
	return true;
	
}

int main()
{
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&rooms[i]);
	}
	
	
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&d[i],&s[i],&t[i]);
	}
	
	int l=0,r=m;
	
	while(l<r)
	{
		int mid=r+l+1>>1;           //ΪʲôҪ+1��  ��Ϊ�߽����⣬+1�ǳ���Ҫ 
		//cout<<mid<<endl;
		if(check(mid))l=mid;//��ȷ���Ǿͼ����������� 
		else r=mid-1;//check����fasle���Ǳ�ʾ����������Ҫ�鿴ǰ����Ƿ�Ҳ���� 
	}
	
	//���û�д��󣬶���Ӧ�ö�����r==m�ϣ���Ϊֱ�����һ�춼û�д���
	if(r==m)cout<<0<<endl;
	//���������r==l==mid-1������������Ĵ����һ���ǰһ�� 
	else cout<<-1<<endl<<r+1<<endl; 
	
	return 0;
} 
