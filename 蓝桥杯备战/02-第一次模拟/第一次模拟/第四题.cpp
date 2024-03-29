#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<stack>
#include<unordered_set>
//求约数个数
int getgcdsum(int n) 
{
	unordered_set<int>s;
	int cou = 0;
	for (int i = 1; i <= n; i++) 
	{
		for (int j = i; j <= n; j++) 
		{
			if (i * j == n) 
			{
				if (s.find(i) == s.end()) 
				{
					cou++;
					s.emplace(i);
				}
				if (s.find(j) == s.end())
				{
					cou++;
					s.emplace(j);
				}


			}
		}
	}
	return cou;
}
int main() 
{
	int k1 = getgcdsum(16);
	int k2 = getgcdsum(8);
	cout << k1<<endl;
	cout << k2 << endl;
	//验证完毕，正确
	/*
	393353 901440 123481 850930 423154 240461
	373746 232926 396677 486579 744860 468782
	941389 777714 992588 343292 385198 876426
	483857 241899 544851 647930 772403 109929
	882745 372491 877710 340000 659788 658675
	296521 491295 609764 718967 842000 670302
	*/
	vector<int>aim = 
	{
	393353, 901440, 123481, 850930 ,423154 ,240461,
	373746, 232926 ,396677 ,486579,744860 ,468782,
	941389 ,777714, 992588, 343292, 385198 ,876426,
	483857 ,241899 ,544851, 647930, 772403 ,109929,
	882745 ,372491, 877710 ,340000 ,659788, 658675,
	296521 ,491295, 609764 ,718967, 842000 ,670302
	};
	int max = 0;
	int maxn;
	for (auto ele : aim) 
	{
		int r = getgcdsum(ele);
		if (r > max) 
		{
			max = r;
			maxn = ele;
		}
	}
	cout << max<<endl;
	cout << maxn << endl;
	return 0;
}