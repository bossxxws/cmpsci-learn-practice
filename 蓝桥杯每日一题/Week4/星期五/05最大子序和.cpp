#include<bits/stdc++.h>

using namespace std;

const int N=300000+10;

int n,m; 

long long  s[N];

int q[N],hh=-1,tt;

int main()
{
	cin>>n>>m;
	
	//ǰ׺�� 
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		s[i]+=s[i-1];
	}
	
	long long res=INT_MIN;
	for(int i=1;i<=n;i++)
	{
		//�ж��Ƿ񻬳����� 
		if(hh<=tt && q[hh]<=i-m-1)hh++;
		
		res=max(res,s[i]-s[q[hh]]);
		
		//s[q[tt]] ��������ȥ����Ȼ��ԽСԽ�� 
		//���s[i](ǰi�����ĺ�)С��s[q[tt]](ǰ���ǰ׺��)
		//��ôs[i]���ʺϱ���ȥ��������ǰ׺�� 
		while(hh<=tt && s[q[tt]]>=s[i])tt--;
		
		//��ǰ����� 
		q[++tt]=i;
				
	}
	cout<<res;
	return 0;
} 
