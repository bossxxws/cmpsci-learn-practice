#include<bits/stdc++.h>
using namespace std;

int n;

const int N=1003;//最多果树棵树
const int M=1003;//最多操作次数 

int mar[N];//标记最后一次统计操作的位置 

int a[M][M];//存储第i个果树的第i次操作后的状态 、

bool drop[2*M];//模拟环形的状态 

int s[N][N];//前缀和数组存储蔬果的个数 

int op[N];

int main()
{
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		int m;
		cin>>m;//操作次数 
		op[i]=m;
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);//d[i]【1】表示第i棵果树初始状态 
			if(a[i][j]>0)mar[i]=j,s[i][j]=s[i][j-1];//最后一次统计操作是第j次 
			else s[i][j]=s[i][j-1]+a[i][j]; 
//			cout<<s[i][j]<<endl;
		}
	}
//	cout<<"cin over"<<endl;
	//做出T
	int sum=0;
	int D=0;
	for(int i=1;i<=n;i++)
	{
		int j=mar[i];//最后一次统计的下标 
//		cout<<"mar "<<j<<endl; 没问题 
		int sou=a[i][j];//最后一次统计的个数
//		cout<<sou<<endl;没问题 
//		cout<<sou+s[i][op[i]]-s[i][j]<<endl; !!!
		sum+=sou+s[i][op[i]]-s[i][j];
		
		//接下来处理掉落的情况 
		for(int k=1;k<=op[i];k++)
		{
			int sta;
			if(k==1)sta=a[i][k];
			else sta=a[i][k-1];
			
			int p=k;
			
			while(p<op[i] && a[i][p]<=0)p++;//走到统计的地方
			
//			cout<<i<<" "<<k<<" "<<p<<" "<<sta<<" "<<s[i][p]-s[i][k-1]<<endl;
			if(p==op[i] && a[i][p]<=0)break;
			if(a[i][p]!=sta+(s[i][p]-s[i][k-1]))
			{
//				cout<<i<<" "<<
//				a[i][k-1]<<" "<<k-1
//				<<" "<<p<<" "<<
//				a[i][p]<<" "<<sta+(s[i][p]-s[i][k-1])<<endl;
				drop[i]=true;	
				drop[i+n]=true;
				D++;
				break; 
			} 
			k=p;
		}
	} 
	int E=0;

	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		if(drop[i]==true)
		{
			cnt++;
			int j=i+1;
			while(j<=2*n && drop[j]==true && cnt!=3)j++,cnt++;
			if(cnt==3)E++;
//			cout<<i<<" "<<j<<endl;
		}
	}

	
	cout<<sum<<" "<<D<<" "<<E;
	
	return 0;
}
