//#include <iostream>
//using namespace std;
////ȫ�ֺ�������Ԫ
//class Biulding 
//{
//	friend void goodGay(Biulding* biulding);
//	//goodGayȫ�ֺ�����building�����ѣ����Է���Biulding��˽�г�Ա
//	//����Ҫд��public���棬ж�����������Ϳ�����
//public:
//	Biulding() 
//	{
//		m_settingroom = "����";
//		m_bedroom = "����";
//	}
//public:
//	string m_settingroom;//����
//private:
//	string m_bedroom;
//
//};
//void goodGay(Biulding* biulding) 
//{ 
//	cout << "�û���ȫ�ֺ��������ڷ��� �� " << biulding->m_settingroom << endl;
//	cout << "�û���ȫ�ֺ��������ڷ��� �� " << biulding->m_bedroom << endl;
//	
//}
//void test01() 
//{
//	Biulding biulding;
//	goodGay(&biulding);
//}
//int main()
//{
//	test01();
//	system("pause");
//
//	return 0;
//}