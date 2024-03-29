#include <iostream>
using namespace std;
#include<vector>
#include<queue>
//i will put the 1 into the queue.and search the value around the current position
//mark the position then it can not be put in queue again
//method above is wrong

//this is the corret solution:
class Solution 
{
public:
    int numIslands(vector<vector<char>>& grid)
	{
		//count the number of island
		int cou = 0;
		int m = grid.size();
		int n = grid[0].size();
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++) 
			{
				if (grid[i][j] == '1') 
				{
					cou++;
					bfs(grid, i, j);
				}
			}
		}
		return cou;
    }
	void bfs(vector<vector<char>>& grid, int r, int c) 
	{
		int m = grid.size();
		int n = grid[0].size();
		//this is the end condition:
		//1.when the position is out of edge 
		//2.when the position's value is not '1'(island)
		if (r < 0 || c  < 0 || r  > m - 1 || c > n - 1||grid[r][c]=='0')
		{
			return;
		}
		grid[r][c] = '0';
		bfs(grid, r - 1, c);
		bfs(grid, r, c-1);
		bfs(grid, r + 1, c);
		bfs(grid, r, c + 1);

	}
};
int main()
{

	system("pause");

	return 0;
}