#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<stack>
int main() 
{
	int cou = 0;
	int i = 0, t;
	while (1) 
	{
		t = 0;
		for (int j = 0; j < 30; j++) 
		{
			if ((i >> j) & 1) t++;

		}
		if (t == 3) 
		{
			cou++;
			cout << cou << " : " << i << endl;
			if (cou > 23) break;
		}
		i++;
	}
	cout << "下面用数学方法转化二进制" << endl;
	int x;
	cout << "输入x" << endl;
	cin >> x;
	vector<int>res;
	while (x > 0) 
	{
		int a = x % 2;
		res.push_back(a);
		x = x / 2;
	}
	for (auto it = res.rbegin(); it != res.rend(); it++) 
	{
		cout << *it;
	}
	cout << endl<< (int(7 >> 1)) << endl;

	return 0;
}