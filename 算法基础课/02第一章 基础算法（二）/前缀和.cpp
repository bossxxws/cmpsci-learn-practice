#include<iostream>
using namespace std;
const int N=1000010;
int S[N];

int main()
{
	int n,m;
	cin>>n>>m;
	int A[n+1]; 
	A[0]=0;
	S[0]=0;
	for(int i=1;i<=n;i++)cin>>A[i];
	for(int i=1;i<=n;i++)S[i]=S[i-1]+A[i];
	int r,l;
	while(m--)
	{
		cin>>l>>r;
		cout<<S[r]-S[l-1]<<endl;
	}
	return 0;
}
