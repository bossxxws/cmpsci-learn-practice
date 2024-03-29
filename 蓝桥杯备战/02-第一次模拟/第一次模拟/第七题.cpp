#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<stack>
#include<unordered_set>
char getla(string s) 
{
	unordered_set<char>aim = { 'a','e','i','o','u'};
	int n = s.size();
	char res;
	for (int i = 0; i < n; i++) 
	{
		if (!(aim.find(s[i]) == aim.end())) 
		{
			res = s[i];
		}
	}
	return res;
}
int main() 
{
	string x;
	cin >> x;
	char res = getla(x);
	cout << res;
	return 0;
}