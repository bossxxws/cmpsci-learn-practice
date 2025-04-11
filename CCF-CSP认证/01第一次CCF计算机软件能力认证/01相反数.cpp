#include<bits/stdc++.h>

using namespace std;

int n;
const int N=503;

int a[N]; 
int cnt;
int main()
{
	cin>>n;
	
	for(int i=1;i<=n;i++)cin>>a[i];
	
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
//	cout<<endl;
	for(int i=1,j=n;i<j;)
	{
//		cout<<a[i]<<" "<<a[j]<<endl;
		if(abs(a[i])==abs(a[j]) && i!=j)cnt++,i++,j--;
		else if(abs(a[i])<abs(a[j]))//后面的绝对值大 
		{
			while(j-1>=i && abs(a[i])<abs(a[j]))j--;
		}
		else
		{
			while(i+1<=j && abs(a[i])>abs(a[j]))i++;
		}
	}
	
	cout<<cnt;
	
	return 0;
}
