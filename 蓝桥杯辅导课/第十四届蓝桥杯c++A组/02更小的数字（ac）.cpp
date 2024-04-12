#include<bits/stdc++.h>

using namespace std;

const int N=5003;

int n,f[N][N],res;

string s;

int main()
{
    cin>>s;
    
    n=s.size();
    
    for(int len=1;len<=n;len++) 
    {
    	for(int l=0;l+len-1<n;l++)
    	{
    		int r=l+len-1;
    		if(s[r]<s[l])f[l][r]=1;
    		else if(s[l]==s[r])
    		{
    			f[l][r]=f[l+1][r-1];
			}
			res+=f[l][r];
		}
	}
    
    cout<<res;
}
