//һ��ʼû�뵽�����������Ǳ߻��ıߣ���������[n/2]��ȡ�����������е����ֵ���Ǵ�
#include<bits/stdc++.h>

using namespace std;

int t,n;

const int N=5*1e6+5;

char a[N];
int s[N];

int main()
{
	cin>>t;
	int c=1;
	while(t--)
	{
		
		//cout<<"-------"<<endl;
		
		int m;
		cin>>m;
		
		for(int i=1;i<=m;i++)
		{
			cin>>a[i];
		}
		
		//cout<<"-------"<<endl;
		
		for(int i=1;i<=m;i++)
		{
			s[i]=s[i-1]+(a[i]-'0');
		}
		
		int cnt=(m+1)/2;
		int maxs=-1;
		
		for(int i=1;i<=m-cnt+1;i++)
		{
			//����i��j������ڻ��� 
			int j=i+cnt-1;//ע��Ҫ��ȥ1����Ϊֱ�Ӽ��ϻᵼ�¶�һ��ڻ� 
			maxs=max(maxs,s[j]-s[i-1]);
		}
		cout<<"Case #"<<c<<": "<<maxs<<endl;
		c++;
	}
	
	return 0;
}
