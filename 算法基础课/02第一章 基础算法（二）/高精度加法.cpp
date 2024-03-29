#include<iostream>
using namespace std;
#include<string>
#include<vector>
vector<int> add(vector<int> &A,vector<int> &B)
{
	if(A.size()<B.size())return add(B,A);
	vector<int>C;
	int t=0;
	for(int i=0;i<A.size();i++)
	{
		t=t+A[i];
		if(i<B.size())t=t+B[i];
		C.push_back(t%10);
		t=t/10;
	}
	if(t)C.push_back(t);
	return C;
}
int main()
{
	string a,b;
	cin>>a>>b;
	vector<int>A,B;
	for(int i=a.size()-1;i>=0;i--)A.push_back(a[i]-'0');
	for(int i=b.size()-1;i>=0;i--)B.push_back(b[i]-'0');
	vector<int>res=add(A,B);
	for(int i=res.size()-1;i>=0;i--)cout<<res[i];
	return 0;
} 
