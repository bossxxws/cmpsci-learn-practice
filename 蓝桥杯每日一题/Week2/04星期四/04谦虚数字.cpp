#include<bits/stdc++.h>

using namespace std;

int K,n;

const int N=1e5+5;


int a[N],b[N];//b������¼����ָ���λ�� 

int main()
{
	cin>>K>>n;
	
	for(int i=0;i<K;i++)
	{
		cin>>a[i];
	}//������������
	
	sort(a,a+K);
	
	vector<int>res(1,1);
	
	while(res.size()<=n)
	{
		int t=INT_MAX;
		for(int i=0;i<K;i++)t=min(t,res[b[i]]*a[i]);
		res.push_back(t);
		for(int i=0;i<K;i++)
		{
			//����ָ��			
			if(res[b[i]]*a[i]==t)b[i]++;
		}
		
	} 
	cout<<res.back();
	return 0;
}
