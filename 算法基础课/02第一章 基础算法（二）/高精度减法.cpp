#include<iostream>
using namespace std;
#include<string>
#include<vector>
//judge if A>=B
bool cmp(vector<int> A,vector<int> B)
{
	if(A.size()!=B.size())return A.size()>B.size();
	//the position that A.size()==B.size()
	else
	{
		for(int i=A.size()-1;i>=0;i--)
		{
			if(A[i]!=B[i])return A[i]>B[i];
		}
		return true;
	}
}
vector<int> sub(vector<int> &A,vector<int> &B)
{
	//now A is always bigger than B or equal to B
	vector<int>C;
	int t=0;
	for(int i=0;i<A.size();i++)
	{
		if(i<B.size())t=A[i]-B[i]-t;
		else t=A[i]-t;
		C.push_back((t+10)%10);
		if(t<0)t=1;
		else t=0;
	}
	while(C.size()>1 && C.back()==0)C.pop_back();
	return C;
}
int main()
{
	string a,b;
	cin>>a>>b;
	vector<int>A,B;
	for(int i=a.size()-1;i>=0;i--)A.push_back(a[i]-'0');
	for(int i=b.size()-1;i>=0;i--)B.push_back(b[i]-'0');
	if(cmp(A,B))
	{
		vector<int>res=sub(A,B);
		for(int i=res.size()-1;i>=0;i--)cout<<res[i];
	}
	else
	{
		vector<int>res=sub(B,A);
		cout<<"-";
		for(int i=res.size()-1;i>=0;i--)cout<<res[i];
	}
	return 0;
} 
