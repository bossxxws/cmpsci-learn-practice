#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<stack>
int main() 
{
	//��s��ɾ��m����ĸʹ��ʣ�µ��ֵ�����С��s�ĳ���Ϊn
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	string res = "";
	int delcout = 0;
	int rest = 0;
	for (int i = 0; i < n; i++) 
	{
		char c = s[i];
		while (delcout < m && res.length()>0 && c < res.back()) 
		{
			res.pop_back();
			delcout++;
		}
		res += c;

	}
	cout << res;
	return 0;
}