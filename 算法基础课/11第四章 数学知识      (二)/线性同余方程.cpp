//����ax mod m ͬ�� b ���� x  
//�൱��ax=my������x ��y��m�ı����� 
//Ҳ����ax - my =b 
//��Ϊy������ 
//�� y'=y
//Ҳ����ax + my' =b�����һ��x�õ�ʽ����
//Ҳ������չŷ����ã�b�����Լ����
//Ҫ�õ�ʽ�н⣬ 
//��Ϊa�����Լ���ı�����mҲ�����Լ���ı���������ax+my'Ҳ�����Լ���ı���
//b �����Լ���ı��� ,��һ���н� 
//�����н�ĳ�ֱ�Ҫ��������ax+my'��b��������a��m��      
//(��,��)���� 
//�����Ϊ��չŷ������㷨�����ax + my' =d 
//������ ��ʽ�ұ�Ϊb ��b����Ŀ����������b��Ҫ��d�ı��������д𰸣� 
//��һ��ʽ�ӵ�ʽ����ͬʱ���ϣ�b/d�� ���ó����������ʽ�� 
//�������x��Ҫ���ϣ�b/d��,����Ҫmod m 
//�������˼�LL ������xӦ����m�ķ�Χ�ڣ���Ϊax mod m��x������m�ķ�Χ�ڣ� 
#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

int exgcd(int a,int b,int &x,int &y)
{
	if(!b)//bΪ0ʱ,ax+byֻʣa����ʱ��d=a����ʽax=a����x=1 
	{
		x=1,y=0;
		return a; 
	}
	int d=exgcd(b,a%b,y,x);
	
	y=y-a/b*x;
	
	return d;
	
}
	

int main()
{
	int n;
	cin>>n;
	

	while(n--)
	{
		int a,b,m;
		cin>>a>>b>>m;
		
		int x,y;
		
		int d=exgcd(a,m,x,y);
		if(b%d)cout<<"impossible"<<endl;
		else cout<<(LL) x * (b/d) % m<<endl;//b������d��a��m�����Լ�������д�
	}
	
	
	
	return 0;
}
