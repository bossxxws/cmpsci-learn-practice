//#include <iostream>
//using namespace std;
//#include<fstream>
//#include<string>
////�ı��ļ� ���ļ�
//void test01() 
//{
//	ifstream ifs;
//	ifs.open("text.txt", ios::in);
//	if (!ifs.is_open()) //! ȡ�����ţ��ж�û�д�
//	{
//		cout << "�ļ���ʧ����" << endl;
//		return;
//	}
//	//�����ݷ���
//	////��һ�ַ���
//	//char buf[1024] = { 0 };
//	////����������ŵ�buf��
//	//while (ifs >> buf) 
//	//{
//	//	cout << buf << endl;
//	//}        
//	////�ڶ���
//	//char buf[1024] = { 0 };
//	//while (ifs.getline(buf, sizeof(buf))) 
//	//{
//	//	cout << buf << endl;
//	//}
//	////�����ַ���
//	/*string buf;
//	while(getline(ifs,buf))
//	{
//		cout << buf << endl;
//	}*/
//	//�����ַ���
//	char c;
//	while ((c = ifs.get()) != EOF) 
//	{
//		cout << c;
//	}
//
//
//
//	//�ر��ļ�
//	ifs.close();
//	 
//}
//int main()
//{
//	test01();
//	system("pause");
//
//	return 0;
//}