#include <iostream>
using namespace std;
#include<vector>

//若曹贼来犯，吾为大王吞之！

//构造next数组

int* biuldNext(string s) 
{
	int m = s.size();
	int *N = new int[m];
	
	int i = 0;//i之前字串的最长下标，不算上i本身
	int j = N[0] = -1;//右移来实现以上目的
	while (i < m) //标记的总是后面字符的next表，故减去1刚好
	{
		if ( j < 0 || s[i] == s[j])


		{
			i++;//标记的是上面i后面的数的next表值
			j++;//先j++ ，再N[i] = j   
			N[i] = j;//原因： i之前的最大公共字符串为j(位置的基础上加1表示长度)   用j表示“子串”,s[j]为子串中的位置，再j++则表示字串最大公共长度	
		}
		else 
		{
			j = N[j];//回溯
		}
	}
	return N;	
}

int KMP(string F,string S) 
{
	int *next = biuldNext(S);
	int FL = F.size();
	int SL = S.size();
	int i = 0, j = 0;
	while (i < FL) 
	{
		if (F[i] == S[j]) 
		{
			i++;
			j++;
		}
		else if(j>0)
		{
			j = next[j];//回溯
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



class Solution 
{
public:
	int strStr(string haystack, string needle)
	{
		
	}
};
int main()
{
	string s1 = "ABABCABABD"; 
	string s2 = "ABABD";
	int *n = biuldNext(s1);
	for (int i = 0; i < s1.size(); i++) 
	{
		cout << "Next table: "<<i<<" = "<< n[i] << endl;

	}
	cout << "position: ";
	cout << KMP(s1, s2) << endl;

	system("pause");

	return 0;
}