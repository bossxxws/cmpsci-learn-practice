#include <iostream>
using namespace std;
#include<stack>
#include<map>
stack<int> tower[4];
void moveandshow(int, int, int, int);
void towerofhanoi(int n) 
{
	for (int d=0; d > 0; d--) 
	{
		tower[1].push(d);//put all plates onto tower1
	}
	//move all plates from tower1 to tower3 through tower2
	moveandshow(n, 1, 2, 3);
}
void moveandshow(int n, int x, int y, int z) 
{
	if (n > 0) 
	{
		moveandshow(n - 1, x, z, y);
		int d = tower[x].top();
		tower[x].pop();
		tower[y].push(d);
		//show the tower showState();
		moveandshow(n - 1, z, y, x);
	}
}

int main()
{

	system("pause");

	return 0;
}