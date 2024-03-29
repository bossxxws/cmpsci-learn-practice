#include <iostream>
using namespace std;
#include<vector>

class Solution
{
public:
	vector<int> getRow(int rowIndex) 
	{
		vector<vector<int>>v;
		v.resize(rowIndex+1);
		v[0].resize(1);
		v[0][0] = 1;
		for (int i = 1; i < rowIndex+1; i++)
		{
			v[i].resize(i + 1);
			v[i][0] = 1;
			v[i][i] = 1;

			for (int j = 1; j < i; j++)
			{
				if (j < v[i - 1].size())
				{
					v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
				}

			}
		}
		return v[rowIndex];
	}
};

int main()
{
	Solution s;
	vector<int> k = s.getRow(5);
	cout << k[2] << endl;

	system("pause");

	return 0;
}