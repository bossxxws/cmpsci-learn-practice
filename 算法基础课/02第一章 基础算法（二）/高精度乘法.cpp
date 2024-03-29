#include<iostream>
using namespace std;
#include<vector>
vector<int> mul(vector<int> &A,int b)
{
	vector<int>C;
	int t=0; 
	for(int i=0;i<A.size() || t;i++)
	{
		if(i<A.size()) t+=A[i]*b;
		C.push_back(t%10);
		t/=10;
	}
	vector<int>s={0};
	if(C.back()!=0)return C;
	else return s;
}
int main()
{
	string a;
	int b;
	cin>>a>>b;
	vector<int>A;
	for(int i=a.size()-1;i>=0;i--)A.push_back(a[i]-'0');
	auto C=mul(A,b);
	for(int i=C.size()-1;i>=0;i--)cout<<C[i];
	return 0;
}
