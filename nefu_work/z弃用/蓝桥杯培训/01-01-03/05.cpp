/*
Problem:E
Time Limit:1000ms
Memory Limit:65535K
Description
QWQ拥有一台破烂的翻译机，作为他在星际旅行时候的必备物品，某日，他来的一颗名为倒置星的星球，这个星球上的所有东西都是倒置的，
就连说话也要倒过来说，
比如，translate在这颗星球上就是etalsnart，QWQ想依靠这台破烂的翻译机完成语言交流，然而，这台翻译机每次翻译的结果并不一定是正确的，
你能告诉QWQ每次翻译的结果是否正确么？如果争取就输出’YES‘，否则输出’NO‘。
Input
每组输入占2行
第一行位QWQ想说的话
第二行位翻译机翻译的结果
每句话的长度不超过100个字符
Output
每组输出占一行
YES或者NO
Sample Input
样例一：
code
edoc

样例二：
abb
aba
Sample Output
样例一：
YES

样例二：
NO
*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
	string s1,s2;
	cin>>s1>>s2;
	vector<char>aim;
	for(int i=s1.size()-1;i>=0;i--)
	{
		aim.push_back(s1[i]);
	}
	string res="";
	for(int i=s1.size()-1;i>=0;i--)
	{
		res+=s1[i];
	}
	if(res==s2)cout<<"YES";
	else cout<<"NO";
	return 0;
}
