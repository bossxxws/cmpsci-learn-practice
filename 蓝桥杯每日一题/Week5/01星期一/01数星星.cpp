#include<bits/stdc++.h>
//��Ҫ��������������� 
//1��0~x�����ĸ������Ż������һ�������ֹ�����1���������԰���ǰ׺�ĸ���ת��Ϊ��ǰ׺�ͣ� 
//2�����һ����x 

//�����ض�������ѡ���ض������ݽṹ

//����ѡ����״���飨���Կ���֧�����������������߶���Ҳ���ԣ� 
//��״�����ܲ������߶������ܲ��� 
 
//��״�������⣬�±�Ҫ��1��ʼ 
using namespace std;

const int N=15000+10; 

const int Max=32010;//�������ֵ 

int n;


int level[N],tree[Max];//�𰸡���״���� 

//��״�������������

int lowbit(int x)
{
	return x&-x;//���ص���x�Ķ����Ʊ�ʾ�����һλ1 
} 

int query(int x)
{
	//query��ʾ��ѯ1~x���ܺ�
	int res=0;
	for(int i=x;i!=0;i-=lowbit(i))
	{
		res+=tree[i];
	}
	return res;
}

//add��ʾ��ĳһ��λ�ü���һ����
void add(int x,int v)
{
	for(int i=x;i<Max;i+=lowbit(i))
	{
		tree[i]+=v;
	}
 } 

int main()
{
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x++;//��״�����±��1��ʼ 
		int t=query(x);//ͳ��һ��1~x�������ܺ� ��Ҳ���Ǻ����귶ΧΪ1~x�����ǵ������� 
		level[t]++;//����ȼ���������++�� 
		add(x,1);//�ѵ�ǰ���ӵ���״���鵱�� 
	}
	
	for(int i=0;i<n;i++)
	{
		printf("%d\n",level[i]);
	 } 
	
	return 0;
} 
//��״�����ܿ��ٵ���ǰ׺��O(log n)
//�ܿ����޸�ĳһ����O��log n�� 
