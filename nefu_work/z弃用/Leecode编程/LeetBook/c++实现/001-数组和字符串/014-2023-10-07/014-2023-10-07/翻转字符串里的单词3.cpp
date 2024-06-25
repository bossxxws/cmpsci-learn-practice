#include <iostream>
using namespace std;
#include<vector>

class Solution
{
public:
	string reverseWords(string s)
	{
		int n = s.size();
		int i = 0;
		int star = 0;
		while (i < n) 
		{
			while (i<n&&s[i]!=' ')
			{
				i++;
			}
			int tem = i-1;
			while (star < tem) 
			{
				swap(s[star++], s[tem--]);
			}
			star = i+1;
			i = i + 1;
		}
		return s;

	}
};
int main()
{
	string s = "the sky is blue";
	Solution S;
	string k = S.reverseWords(s);
	cout << k << endl;
	system("pause");

	return 0;
}