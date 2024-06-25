//#include <iostream>
//using namespace std;
//#include<vector>
//
//class Solution
//{
//public:
//
//	void rotate(vector<vector<int>>& matrix)
//	{
//		int n = matrix.size();
//
//		//Ð±¶Ô³ÆÐý×ª
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < i + 1; j++) 
//			{
//				swap(matrix[i][j], matrix[j][i]);
//			}
//		}
//
//		//¾µÏñÐý×ª
//		for (int row = 0; row < matrix.size(); row++)
//		{
//			for (int column = 0; column < matrix.size() / 2; column++) 
//			{
//				swap(matrix[row][column], matrix[row][matrix.size() - column - 1]);
//			}
//		}
//
//
//	}
//};
//int main()
//{
//
//	system("pause");
//
//	return 0;
//}