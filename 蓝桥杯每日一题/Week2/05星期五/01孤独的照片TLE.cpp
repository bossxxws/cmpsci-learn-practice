#include<bits/stdc++.h>

using namespace std;

int n; 

const int N=5e5+3;

char a[N];

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%s",&a[i]);//G H
	//for(int i=1;i<=n;i++)printf("%c\n",a[i]);//G H
	int res=0;
	
	for(int i=1;i<=n;i++)
	{
	    int cntg=0,cnth=0;
	    for(int j=i;j<=n;j++)
		{
			if(a[j]=='G')cntg++;
			else if(a[j]=='H')cnth++;
			//cout<<cntg<<" "<<cnth<<endl;
			if(j-i>=2)
			{
				if(cnth==1 || cntg==1)res++;//cout<<cnth<<" "<<cntg<<endl;
			}
		} 
	}

    cout<<res;
	
	return 0;
} 
