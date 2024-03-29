#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<stack>
int getmax(vector<int>aim,int k)
{
	int si = aim.size();
	int max = 0;
	for (int i = 0; i < si; i++) 
	{
		for (int j = i; j + k < si; j++) 
		{

			int sum = 0;
			for (int x = j; x < j+k; x++) 
			{
				sum = sum + aim[x];
			}
			if (sum > max)
			{
				max = sum;
			}
		}
	}
	return max;

}
int main() 
{
	int n;
	int k;
	cin >> n;
	cin >> k;
	vector<int>aim;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		aim.push_back(m);
	}
	int res = getmax(aim, k);
	cout << res;
	return 0;
}