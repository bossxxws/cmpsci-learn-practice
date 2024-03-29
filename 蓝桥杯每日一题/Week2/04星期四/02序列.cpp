//¶þ²æ¶Ñ 
#include<bits/stdc++.h>

using namespace std;

int T;

typedef pair<int,int> PII;

#define x first

#define y second

int m,n;



const int N=3000;

int a[N],b[N],c[N];
 
void merge()
{
    priority_queue<PII,vector<PII>,greater<PII>> minheap;
	for(int i=1;i<=n;i++)minheap.push({a[1] + b[i],1});
	for(int i=1;i<=n;i++)
	{
		PII t=minheap.top();
		minheap.pop();
		int s=t.x;
		int p=t.y;
		c[i]=s;
		minheap.push({s-a[p]+a[p+1],p+1});
	}
	
	for(int i=1;i<=n;i++)a[i]=c[i];
}
int main()
{
	cin>>T;
	
	while(T--)
	{

		cin>>m>>n;
		
		for(int i=1;i<=n;i++)cin>>a[i];
		
		sort(a+1,a+n+1);
		
		for(int i=0;i<m-1;i++)
		{
			for(int j=1;j<=n;j++)cin>>b[j];
			merge();
		}
		
		for(int i=1;i<=n;i++)cout<<a[i]<<" ";
		cout<<endl;
		
	}
		
	return 0;
}
