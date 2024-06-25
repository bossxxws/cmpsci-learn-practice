#include <iostream>
using namespace std;
#include<string>

class Solution
{
public:
	string longestPalindrome(string s)
	{
		int n = s.size();
		int i = 0, j = 0;
		//奇数回文
		for (int k = 1; k < n ; k++)
		{

			int i0 = k;
			int j0 = k;
			while (i0 > 0 && j0 < n -1)
			{
				
				if (s[i0-1] == s[j0+1])
				{
					i0--;
					j0++;
				}
				else
				{
					break;
				}
			}
			if (j0 - i0 > j - i)
			{
				i = i0;
				j = j0;
			}
		}
		//偶数回文
		for (int k = 1; k < n ; k++)
		{

			int i0 = k ;
			int j0 = k-1;
			while (i0 > 0 && j0 < n-1 )
			{
				
				if (s[i0-1] == s[j0+1])
				{
					i0--;
					j0++;
				}
				else
				{
					break;
				}
			}
			if (j0 - i0 > j - i)
			{
				i = i0;
				j = j0;
			}
			
		}
	
		return s.substr(i, j - i + 1);
	}
};

int main()
{
	string str1 = "cbbdb";
	Solution s1;
	string s= s1.longestPalindrome(str1);
	cout << s << endl;
	system("pause");

	return 0;
}

//一道题搞半天