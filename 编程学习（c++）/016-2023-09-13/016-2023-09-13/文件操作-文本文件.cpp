#include <iostream>
using namespace std;
#include<fstream>//ͷ�ļ�����
// �ı��ļ� д�ļ�
void test01() 
{
	//1������ͷ�ļ�fstream
	//2������������
	ofstream ofs;//o�����f�ļ���stream�������ļ����������д�ļ�
	//3��ָ���򿪷�ʽ
	ofs.open("text.txt", ios::out);
	//4��д����
	ofs << "���������" << endl;
	ofs << "���ӣ������������" << endl;
	//5���ر��ļ�
	ofs.close();
}
int main()
{
	test01();

	system("pause");

	return 0;
}