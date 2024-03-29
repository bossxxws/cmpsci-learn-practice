#include<bits/stdc++.h>

using namespace std;

const int N=1e4;

int t[N];

int f(int x)
{
	if(x==1)return 1;
	if(x==0)return 0;
	int k;
	if(t[x])k=t[x];
	else k=f(x-1)+f(x-2);
	
	return k;
	
}

int main()
{
	t[0]=0;
	t[1]=1;
	
	cout<<f(6);
	
	return 0;
}
