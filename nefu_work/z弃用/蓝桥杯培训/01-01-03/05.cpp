/*
Problem:E
Time Limit:1000ms
Memory Limit:65535K
Description
QWQӵ��һ̨���õķ��������Ϊ�����Ǽ�����ʱ��ıر���Ʒ��ĳ�գ�������һ����Ϊ�����ǵ�������������ϵ����ж������ǵ��õģ�
����˵��ҲҪ������˵��
���磬translate����������Ͼ���etalsnart��QWQ��������̨���õķ����������Խ�����Ȼ������̨�����ÿ�η���Ľ������һ������ȷ�ģ�
���ܸ���QWQÿ�η���Ľ���Ƿ���ȷô�������ȡ�������YES�������������NO����
Input
ÿ������ռ2��
��һ��λQWQ��˵�Ļ�
�ڶ���λ���������Ľ��
ÿ�仰�ĳ��Ȳ�����100���ַ�
Output
ÿ�����ռһ��
YES����NO
Sample Input
����һ��
code
edoc

��������
abb
aba
Sample Output
����һ��
YES

��������
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
