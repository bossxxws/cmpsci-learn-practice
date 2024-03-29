#include <iostream>
using namespace std;
#include<vector>;

class Solution 
{
public:
	vector<int>rowc;
	vector<int>colc;
	void setZeroes(vector<vector<int>>& matrix)
	{
		//把有0的行和列分别存进去两个数组
		int r = matrix.size();
		int c = matrix[0].size();
		for (int i = 0; i < r; i++)
		{	
			//全部遍历，检查0的存在
			for (int j = 0; j < c; j++)
			{
				if (!matrix[i][j])
				{
					rowc.push_back(j);
					colc.push_back(i);
				}
			}
		}
		//把带0的行和列赋值为0
		for (int rc = 0; rc < rowc.size(); rc++) 
		{
			for (int k = 0; k < r; k++) 
			{
				matrix[k][rowc[rc]] = 0;
			}
		}
		for (int cc = 0; cc < colc.size(); cc++)
		{
			for (int k = 0; k < c; k++)
			{
				matrix[colc[cc]][k] = 0;
			}
		}
	}
};

int main()
{

	system("pause");

	return 0;
}