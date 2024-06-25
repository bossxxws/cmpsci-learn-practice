#include <iostream>
using namespace std;
#include<vector>

class Solution
{
public:
	Solution() 
	{
		cout << "SSS构造函数的调用SSS" << endl;
	}
	void S(int) 
	{
		cout << "构造函数调用" << endl;
	};
	vector<int> next;
	//构造函数
	void biuldNext(string s)
	{
		cout << "构造函数调用" << endl;
		int m = s.size();
		
		next.resize(m);
		int i = 0;//i之前字串的最长下标，不算上i本身
		int j = next[0] = -1;//右移来实现以上目的
		while (i < m - 1) //标记的总是后面字符的next表，故减去1刚好
		{
			if (j < 0 || s[i] == s[j])
			{
				i++;//标记的是上面i后面的数的next表值
				j++;//先j++ ，再N[i] = j   
				next[i] = j;//原因： i之前的最大公共字符串为j(位置的基础上加1表示长度)   用j表示“子串”,s[j]为子串中的位置，再j++则表示字串最大公共长度	
			}
			else
			{
				j = next[j];//回溯
			}
		}
		
	}
	int strStr(string haystack, string needle)
	{
		if (needle.size() == 0) 
		{
			return 0;
		}
		biuldNext(needle);
		int FL = haystack.size();
		int SL = needle.size();
		int i = 0, j = 0;
		while (i < FL && j<SL)
		{
			if (haystack[i] == needle[j])
			{
				i++;
				j++;
			}
			else if (j > 0)
			{
				j = next[j];
			}
			else
			{
				i++;
			}
		}
		if (j == SL)
		{
			return i - j;//返回从主串开始完全匹配的第一个位置
		}
		else
		{
			return -1;
		}


	}




};

int main()
{
	Solution s;
	Solution a;
	Solution d;
	string s1 = "ABABCABABD";
	string s2 = "ABABD";
	
	s.biuldNext(s2);
	cout << "构造Next表： "  ;
	for (int i = 0; i < s2.size(); i++) 
	{
		 cout<< s.next[i]<<"  ";
	}
	cout << endl;
	

	cout << s.strStr(s1, s2) << endl;
	

	system("pause");

	return 0;
}