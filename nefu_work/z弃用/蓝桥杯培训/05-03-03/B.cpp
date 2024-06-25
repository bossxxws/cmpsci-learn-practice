#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

unordered_map<LL,LL>m,re;

LL odd(LL x)
{
	x=x*3;
	x+=1;
	return x;
}

LL even(LL x)
{
	x/=2;
	return x;
}

int main()
{
	int l,r;
	cin>>l>>r;
	
	int big=0;
	int res;
	for(int i=l;i<=r;i++)
	{
		LL t=i;int cnt=0;
		
		while(t!=1)
		{
			if(re[t])
			{
				re[i]=cnt+re[t];
				cnt=re[i];
				break;
			}
			cnt++;
			if(m[t])t=m[t];
			else if(t%2==0)
			{
				m[t]=even(t);
				t=m[t];
				//cout<<t<<"¡¡";
			}
			else
			{
				m[t]=odd(t);
				t=m[t];
				//cout<<t<<"¡¡"; 
			}
		} 
		
		re[i]=cnt;
		
		if(cnt>big)
		{
			//cout<<i<< " "<<cnt<<endl;
			big=cnt;
			res=i;
		}
		
	}
	cout<<res<<endl;//<<" "<<re[res];
}
