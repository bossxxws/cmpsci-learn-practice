//#include <iostream>
//using namespace std;
////��ģ���뺯��ģ�������
//template<class NameType,class AgeType = int>
//class Person
//{
//public:
//	Person(NameType name, AgeType age )
//	{
//		this->m_Name = name;
//		m_Age = age;//�ò���this��û��������ͻ������£�����ʡ��thisָ��
//		//�ڳ�Ա�����У�����Ա�����Ͳ���������ͬʱ������ʹ�� this ָ�����������ǡ�
//		//ʹ�� this->m_Age ��ʾ���ʵ�ǰ����ĳ�Ա���� m_Age��
//	}
//	void showPerson()
//	{
//		cout << "name " << m_Name << endl;
//		cout << "age " << this->m_Age << endl;
//	}
//
//	NameType m_Name;
//	AgeType m_Age;
//
//};
////1����ģ��û���Զ������Ƶ���ʽ
//void test01() 
//{
//	//Person p("�����",999) �����޷����Զ������Ƶ�
//	Person<string, int>p("�����", 1000);
//	p.showPerson();
//}
//
////2����ģ����ģ������б��п�����Ĭ�ϲ���
//void test02() 
//{
//	Person<string>p("��˽�", 999);
//	p.showPerson();
//}
//int main()
//{
//	test01();
//	test02();
//
//	system("pause");
//
//	return 0;
//}