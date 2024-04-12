#include<bits/stdc++.h>

using namespace std;

const int N=5003;

int res;

string a; 

bool f[N][N];//反转i到j的区间是否比原来的数小 

int main()
{
	cin>>a;
	int n=a.size();
	reverse(a.begin(),a.begin()+2);//排到第二个参数之前的一个 
	cout<<"now a is "<<a<<endl;
	//cout<<a.size(); 
	//reverse(a.begin(),a.begin()+n);
	//cout<<a<<endl;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<=n;j++)
		{

			
			//int old=stoi(a);
			//210102
			//cout<<old<<endl;
			//cout<<i<<" "<<j;
			reverse(a.begin()+i,a.begin()+j);
			//out<<a<<endl;
			string ne=a;
			//int ne=stoi(a);
			
			reverse(a.begin()+i,a.begin()+j);
			//cout<<ne<<" "<<old<<endl;
			//cout<<a<<endl;
			
			//cout<<ne<<endl;
			if(ne<a)res++;
			
		
		}
	
	//char *shit=new char[100];
	cout<<res;
	//string a="00320103";
	//int b=stoi(a);
	//cout<<b;
	
	return 0;
}
