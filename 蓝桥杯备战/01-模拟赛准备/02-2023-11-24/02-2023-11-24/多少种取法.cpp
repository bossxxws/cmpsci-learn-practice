#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<stack>
int main() 
{
	vector<int>s = { 99, 22, 51, 63, 72, 61, 20, 88, 40, 21, 63, 30, 11, 18, 99, 12, 93, 16, 7, 53, 64, 9, 28, 84, 34, 96, 52, 82, 51, 77 };
	int cou = 0;
	int si = s.size();
	for (int i = 0; i < si; i++)
	{
		for (int j = 0; j < si; j++) 
		{
			if (i != j && s[i] * s[j] >= 2022) cou += 1;
		}
	}
	cout << si << endl;
	cout << cou / 2 << endl;;
	cout << 29 * 30/2;
	return 0;
}