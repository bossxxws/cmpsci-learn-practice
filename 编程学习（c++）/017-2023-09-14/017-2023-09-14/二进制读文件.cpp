//#include <iostream>
//using namespace std;
//#include<fstream>
////�����ƶ��ļ�
//class Person 
//{
//public:
//	char m_Name[64];//����
//	int m_Age;//����
//
//
//};
//void test01() 
//{
//	//1 ����ͷ�ļ� �ļ���
//	//2 ����������
//	ifstream ifs;
//	//3 ���ļ� �ж��ļ��Ƿ�򿪳ɹ�
//	ifs.open("person.txt",ios::in|ios::binary);
//	if (!ifs.is_open())
//	{
//		cout << "�ļ���ʧ��" << endl;
//		return;
//	}
//	//4 ���ļ�
//	Person p;
//	ifs.read((char*)&p, sizeof(Person));
//	cout << "����  " << p.m_Name << "����" << p.m_Age << endl;
//	//5 �ر��ļ�
//	ifs.close();
//}
//
//int main()
//{
//
//	system("pause");
//
//	return 0;
//}