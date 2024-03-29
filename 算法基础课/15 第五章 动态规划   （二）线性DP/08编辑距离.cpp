#include<bits/stdc++.h>

using namespace std;

const int N=1010;

int n,m; 

int f[N][N];

char str[N][15];

int editdistance(char a[],char b[])
{
	int lena=strlen(a+1);
	int lenb=strlen(b+1);
	
	for(int i=0;i<=lena;i++)f[i][0]=i;//É¾³ı 
	for(int i=0;i<=lenb;i++)f[0][i]=i;//Ôö 
	
	for(int i=1;i<=lena;i++)
		for(int j=1;j<=lenb;j++)
		{
			f[i][j]=min(f[i-1][j]+1,f[i][j-1]+1);
			
			if(a[i]==b[j])f[i][j]=min(f[i][j],f[i-1][j-1]);
			else f[i][j]=min(f[i][j],f[i-1][j-1]+1);
			
			
		}
	return f[lena][lenb];
}

int main()
{
	scanf("%d%d",&n,&m);
	
	for(int i=0;i<n;i++)scanf("%s",str[i]+1);
	

	
	while(m--)
	{
		char s[15];
		
		int limit;
		int res=0;
		scanf("%s%d",s+1,&limit);
		
		for(int i=0;i<n;i++)
		{
			if(editdistance(str[i],s)<=limit)res++;
		}
		cout<<res<<endl;
	}
	

	return 0;
} 
