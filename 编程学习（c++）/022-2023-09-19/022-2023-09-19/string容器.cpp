#include <iostream>
using namespace std;
#include<string>

//string�Ĺ��캯��

void test01() 
{
	string s1;//Ĭ�Ϲ���
	const char* s = "hello world";
	string s2(s);//ʹ���ַ���s��ʼ��
	cout << "s2 =  " << s2 << endl;
	string s3(s2);//��������
	cout << "s3 " << s3 << endl;
	string s4(10, 'a');//ʹ��n���ַ�����ʼ��
	cout << " " << s4 << endl;
}
int main()
{
	test01();
	system("pause");

	return 0;
}