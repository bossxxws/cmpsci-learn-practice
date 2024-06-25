#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<stack>
int ans = 0;
void dfs(int x, int L, int R)
{
	if (L != 0 && L == R) ans++;
	if (x == 4)return;
	for (int i = 0; i <= 9; i++) 
	{
		if (L == 0 && i == 0)continue;
		for (int j = 0; j <= 9; j++) 
		{
			dfs(x + 1, L + i, R + j);
		}
	}
}
int main() 
{
	dfs(0, 0, 0);
	cout << ans;
	return 0;
}