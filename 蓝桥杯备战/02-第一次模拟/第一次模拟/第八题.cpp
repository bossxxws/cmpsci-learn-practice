#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<stack>
int chan(int n) 
{
	vector<int>aim;
	int res = 1;
	while (n > 10)
	{
		while (n > 0) 
		{
			int tem = n % 10;
			aim.push_back(tem);
			n = n / 10;
		}
		for (auto ele : aim) 
		{
			if (ele != 0) 
			{
				res = res * ele;
			}
		}
		aim.clear();
		n = res;
		res = 1;
	}
	return n;
}
int main() 
{
	int x;
	cin >> x;
	int res = chan(x);
	cout << res;
	return 0;
}