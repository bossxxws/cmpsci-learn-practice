#include <iostream>
using namespace std;
#include<vector>

class Solution
{
public:
	Solution() 
	{
		cout << "SSS���캯���ĵ���SSS" << endl;
	}
	void S(int) 
	{
		cout << "���캯������" << endl;
	};
	vector<int> next;
	//���캯��
	void biuldNext(string s)
	{
		cout << "���캯������" << endl;
		int m = s.size();
		
		next.resize(m);
		int i = 0;//i֮ǰ�ִ�����±꣬������i����
		int j = next[0] = -1;//������ʵ������Ŀ��
		while (i < m - 1) //��ǵ����Ǻ����ַ���next���ʼ�ȥ1�պ�
		{
			if (j < 0 || s[i] == s[j])
			{
				i++;//��ǵ�������i���������next��ֵ
				j++;//��j++ ����N[i] = j   
				next[i] = j;//ԭ�� i֮ǰ����󹫹��ַ���Ϊj(λ�õĻ����ϼ�1��ʾ����)   ��j��ʾ���Ӵ���,s[j]Ϊ�Ӵ��е�λ�ã���j++���ʾ�ִ���󹫹�����	
			}
			else
			{
				j = next[j];//����
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
			return i - j;//���ش�������ʼ��ȫƥ��ĵ�һ��λ��
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
	cout << "����Next�� "  ;
	for (int i = 0; i < s2.size(); i++) 
	{
		 cout<< s.next[i]<<"  ";
	}
	cout << endl;
	

	cout << s.strStr(s1, s2) << endl;
	

	system("pause");

	return 0;
}