#include<iostream>
using namespace std;
const int N=1e5+10;
int a[N],b[N];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i = 0;i < n; i++) cin>>a[i];
    for(int j = 0;j < m; j++) cin>>b[j];
    int j=0;
	for(int i=0;i<m;i++)
	{
		if(j<n&&a[j]==b[i])j++;
	}
	if(j==n)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
    return 0;
}

