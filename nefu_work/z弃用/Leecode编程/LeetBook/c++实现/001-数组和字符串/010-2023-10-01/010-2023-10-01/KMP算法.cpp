#include <iostream>
using namespace std;
#include<vector>

//��������������Ϊ������֮��

//����next����

int* biuldNext(string s) 
{
	int m = s.size();
	int *N = new int[m];
	
	int i = 0;//i֮ǰ�ִ�����±꣬������i����
	int j = N[0] = -1;//������ʵ������Ŀ��
	while (i < m) //��ǵ����Ǻ����ַ���next���ʼ�ȥ1�պ�
	{
		if ( j < 0 || s[i] == s[j])


		{
			i++;//��ǵ�������i���������next��ֵ
			j++;//��j++ ����N[i] = j   
			N[i] = j;//ԭ�� i֮ǰ����󹫹��ַ���Ϊj(λ�õĻ����ϼ�1��ʾ����)   ��j��ʾ���Ӵ���,s[j]Ϊ�Ӵ��е�λ�ã���j++���ʾ�ִ���󹫹�����	
		}
		else 
		{
			j = N[j];//����
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
			j = next[j];//����
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