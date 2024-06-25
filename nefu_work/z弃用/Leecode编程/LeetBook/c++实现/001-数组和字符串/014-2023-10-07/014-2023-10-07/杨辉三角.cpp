#include <iostream>
using namespace std;
#include<vector>

class Solution 
{
public:
	vector<vector<int>> generate(int numRows)
	{
		vector<vector<int>>v;
		v.resize(numRows);
		v[0].resize(1);
		v[0][0] = 1;
		for (int i = 1; i < numRows; i++) 
		{
			v[i].resize(i+1);
			v[i][0] = 1;
			v[i][i] = 1;
			
			for (int j = 1; j < i ; j++) 
			{
				if (j < v[i - 1].size()) 
				{
					v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
				}
				
			}
		}
		return v;
	}
};
int main()
{
	Solution s;
	vector<vector<int>> k =s.generate(5);
	cout << k[2][0] << endl;
	system("pause");

	return 0;
}