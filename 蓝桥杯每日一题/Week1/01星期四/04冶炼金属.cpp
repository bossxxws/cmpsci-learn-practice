#include<bits/stdc++.h>

using namespace std;

typedef long long LL; 

const int N=1e4+5;
LL a[N],b[N];

int n;

bool check(LL mid)//ұ��ֵΪmid 
{
	for(int i=0;i<n;i++)
	{
		//cout<<a[i]<<endl;
		int t=a[i]/mid;
		//cout<<b[i]<<endl;
		//cout<<t<<" "<<b[i]<<endl;
		if(t<b[i])return false;//������ұ����¼�����false			
	}	
	return true;	
}

bool checksp(LL mid)//ұ��ֵΪmid 
{
	for(int i=0;i<n;i++)
	{
		//cout<<a[i]<<endl;
		int t=a[i]/mid;
		//cout<<b[i]<<endl;
		//cout<<t<<" "<<b[i]<<endl;
		if(t>b[i])return false;//������ұ����¼�����false			
	}	
	return true;	
}


int main()
{
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);	
	}
	
	LL l=1,r=1e9+1;
	
	LL mins=r;
	while(l<r)
	{
		//cout<<r<<endl;
		LL mid=(l+r)/2;
		if(checksp(mid))r=mid;
		else
		{
			l=mid+1;
		}	
	}//ȷ����Сֵ
	
	cout<<l<<" ";
	l=l-1,r=1e9+1;
	while(l<r)
	{
		//cout<<l<<" "<<r<<endl;
		LL mid=(l+r+1)/2;
		if(check(mid))l=mid;
		else r=mid-1;
	}//ȷ�����ֵ
	
	
	cout<<l<<endl; 
	
	
	return 0;
} 
