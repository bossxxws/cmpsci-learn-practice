#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+10;

typedef long long LL;

typedef pair<int,int> PII;

PII op[N];

LL n,m;//����m�μ���
 
priority_queue<LL,vector<PII>> q,qs;//ά��һ���󶥶� 

bool check(LL mid)
{
	int sum=0;
	for(int i=0;i<m;i++)//����m�� 
	{
		int a=q.top().first;
		sum+=a;
		cout<<a<<endl;
		int b=q.top().second;
		int t =a-b;
		q.pop();
		PII p={t,b};
		q.push(p);
		if(sum>=mid)return true;
	} 
	return false;
}

int main()
{
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		q.push({a,b});
	}	
	
	cout<<q.top().first<<endl;
	LL l=1,r=1e15;
	
	while(l<r)
	{
		LL mid=l+r+1>>1;
		if(check(mid))l=mid;
		else r=mid-1;	
	} 
	cout<<l;
	return 0;
}
