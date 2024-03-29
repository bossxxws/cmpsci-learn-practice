#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<stack>
vector<int> getbinary(int n) 
{
	vector<int>res;
	while (n > 0) 
	{
		int k = n % 2;
		res.push_back(k);
		n = n / 2;
	}
	return res;
}
vector<int>getbar(int n) 
{
	vector<int>res;
	while (n > 0)
	{
		int k = n % 8;
		res.push_back(k);
		n = n / 8;
	}
	return res;
}
int getsum(int n) 
{
	int sum = 0;
	while (n > 0) 
	{
		int tem = n % 10;
		sum = sum + tem;
		n = n % 10;
	}
	return sum;
}
int main() 
{
	int cou = -1;
	for (int i=0; i <10000; i++) 
	{
		vector<int> a = getbinary(i);
		vector<int> b = getbar(i);
		int as=0, bs=0;
		for (auto elment1 : a) 
		{
			as = as + elment1;
		}
		for (auto elment2 : b)
		{
			bs = bs + elment2;
		}
		if (as == bs) 
		{
			cou++;
			cout <<cou<<": "<< i << endl;
		}
	}
	return 0;
}