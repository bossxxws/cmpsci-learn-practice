//һ��ƽ��ֵ���ⶼ����ת��Ϊ�������� 

#include<bits/stdc++.h>

using namespace std;

int n,f;//�ܹ�n��أ�ÿ����Ҫ���ٰ���f��� 

const int N=1e5+5;

double q[N]; 

//ǰ׺��
double s[N]; 

bool check(double avg)
{
	//���ǰ׺��ȫ����ȥavg 
	for(int i=1;i<=n;i++)s[i]=s[i-1]+q[i]-avg;
	
	double mins=0; 
	//��Ϊ�������䣬ÿ������������ֵ���������0���Ϳ���
	for(int k=f;k<=n;k++)
	{
		mins=min(mins,s[k-f]);//s[k-f]ʹ���������ٳ���Ϊf,���Ҽ�¼��Ҫ��ȥ��ǰ׺����Сֵ
		if(s[k]-mins>=0)return true;
	} 

	return false;
}

int main()
{
	cin>>n>>f;
	
	double l=0;
	double r=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lf",&q[i]);
		r=max(r,q[i]);
	}
	
	while(r-l>1e-5)
	{
		double mid=(l+r)/2;
		if(check(mid))l=mid;
		else r=mid;
	}
	
	
	cout<<(int)(r*1000);
	return 0;
}
