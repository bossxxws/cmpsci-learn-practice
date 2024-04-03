#include<bits/stdc++.h>

using namespace std;

int n; 

typedef long long LL;

const int N=1e5+5;

int a[N],b[N],c[N]; 

LL res;

int ma[N],mc[N];
//mx[i]统计大不于目前i的数有多少（i前面的数都比i小）  
int main()
{
	cin>>n;
	
	int max1=-1,max2=-1;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]++,max1=max(max1,a[i]); 
	
	for(int i=1;i<=n;i++)scanf("%d",&b[i]),b[i]++;
	
	for(int i=1;i<=n;i++)scanf("%d",&c[i]),c[i]++,max2=max(max2,c[i]);
	
    int maxn=max(max1,max2);
	ma[0]=mc[0]=0;
	for(int i=1;i<=n;i++)
	{
		ma[a[i]]++;
		mc[c[i]]++;
	} 
	
	//处理前缀和
	for(int i=1;i<=N;i++)
	{
		ma[i]+=ma[i-1];
		
		mc[i]+=mc[i-1];	
	} 
    /*
    cout<<ma[b[1]]<<endl;
    cout<<mc[N-5]<<endl;
    cout<<ma[b[2]]<<endl;
    cout<<mc[b[2]]<<endl;
    cout<<ma[b[3]]<<endl;
    cout<<mc[b[3]]<<endl;
    */
	for(int i=1;i<=n;i++)
	{
		res+=(LL)ma[b[i]-1]*(mc[N-1]-mc[b[i]]);
	} 
	
	cout<<res;
	
	return 0;
}
