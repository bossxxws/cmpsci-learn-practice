#include <iostream>
using namespace std;

int main()
{
	int arry[9] = { 4,2,8,0,5,7,1,3,6 };
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8-i; j++)
		{
			if (arry[j ] > arry[j+1])
			{

				int temp = arry[j ];
				arry[j ] = arry[j+1];
				arry[j+1] = temp;
			}
		}
	}
	for(int x = 0;x<9;x++)
	{
		cout << arry[x] << endl;
	}
	system("pause");

	return 0;
}