#include<bits/stdc++.h>

using namespace std;

int n; 

const int N=1010;
int a[N];

int main()
{
	cin>>n;
	
	for(int i=1;i<=n;i++)cin>>a[i];
	
	sort(a+1,a+n+1);
	
	int cnt=0;
	for(int i=1;i+1<=n;i++)
	{
//		cout<<a[i]<<" "<<a[i+1]<<endl;
		if(a[i]==(a[i+1]-1))cnt++;
	}
	cout<<cnt;
	return 0;
}
