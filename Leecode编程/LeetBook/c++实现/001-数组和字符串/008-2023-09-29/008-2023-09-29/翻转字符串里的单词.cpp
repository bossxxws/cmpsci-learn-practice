#include <iostream>
using namespace std;
#include<vector>



class Solution 
{
public:
	
	string reverseWords(string s) 
	{
		//ȥ������Ŀո�
		int N = s.length();
		int i = 0, j = 0;
		while (i < N) 
		{
			while (i < N && s[i] == ' ')
			{
				i++;
			}
			while (i < N && s[i] != ' ')
			{
				swap(s[j++], s[i++]);

			}
			j++;

		}
	
		
		N = s.length()-1;
		while (s[N] == ' ') 
		{
			N--;
		}
		s = s.substr(0, N+1);
	

		//ԭ�ط�ת
		int star = 0, end = 0, temp;
		reverse(s.begin(),s.end());
		while (star< N) 
		{
			while (end < N && s[end] != ' ')
			{
				end++;
			}
			temp = s[end] == ' ' ? end - 1 : end;
			while (star < temp) 
			{
				swap(s[star++], s[temp--]);
			}
			star = end + 1;
			end = star;
		}
		return s;

	}
};
int main()
{

	Solution s1;
	string s = " hello  world";
	s1.reverseWords(s);
	cout << s1.reverseWords(s) << endl;

	system("pause");

	return 0;
}