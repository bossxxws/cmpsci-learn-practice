#include <iostream>
using namespace std;
#include<vector>

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat)
    {
        vector<int>v1;
        int m = mat.size();
        int n = mat[0].size();
        int tol = m + n -1;
        vector<int>mem;
        
        if (mat.empty()) 
        {
            return v1;
        }
        for (int i = 0; i < tol; i++) 
        {
            if (i % 2) 
            {
                if (i < n) 
                {
                    int col = i;
                    int row = i - col;
                    while (col >= 0 && row < m)
                    {
                        mem.push_back(mat[row][col]);
                        row++;
                        col--;
                    }
                }
                else 
                {
                    int col = n - 1;
                    int row = i - col;
                    while (col >= 0 && row < m) 
                    {
                        mem.push_back(mat[row][col]);
                        row++;
                        col--;
                    }
                }
            }
            else 
            {
                if (i < m) 
                {
                    int row = i;
                    int col = i - row;
                    while (row >= 0 && col < n) 
                    {
                        mem.push_back(mat[row][col]);
                        row--;
                        col++;
                    }
                }
                else 
                {
                    int row = m - 1;
                    int col = i - row;
                    while (row >= 0 && col < n)
                    {
                        mem.push_back(mat[row][col]);
                        row--;
                        col++;
                    }
                }
                
            }
        
          

        }
        return mem;
    }
};
int main()
{
   
  
	system("pause");

	return 0;
}