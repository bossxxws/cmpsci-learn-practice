//#include <iostream>
//using namespace std;
////�ֱ�������ͨд���Ͷ�̬����ʵ�ּ�����
//
////��ͨд��
//class Calculator 
//{
//public:
//	int getResult(string oper)
//	{
//		if (oper == "+" )
//		{
//			return m_Num1 + m_Num2;
//		}
//		else if (oper == "-")
//		{
//			return m_Num1 - m_Num2;
//		}
//		else if (oper == "*")
//		{
//			return m_Num1 * m_Num2;
//		}
//	}
//	//�������չ�¹��� ��Ҫ�޸�Դ��
//	//����ʵ������ �ᳫ ����ԭ��
//	//����ԭ�򣺶���չ���п��� ���޸Ľ��йر�
//	int m_Num1;
//	int m_Num2;
//
//};
//void test01() 
//{
//	//��������������
//	Calculator c1;
//	c1.m_Num1 = 10;
//	c1.m_Num2 = 10;
//	cout << c1.getResult("+") << endl;
//	cout << c1.getResult("-") << endl;
//	cout << c1.getResult("*") << endl;
//}
////���ö�̬ʵ�ּ�����
////��̬�ô�:
////1����֯�ṹ����
////2���ɶ���ǿ
////3������ǰ�ںͺ�����չ�Լ�ά���Ը�
//
////ʵ�ּ�����������
//class AbstractCalculator 
//{
//public:
//	virtual int getResult() 
//	{
//		return 0;
//	}
//	int m_Num1;
//	int m_Num2;
//};
////�ӷ���������
//class AddCalculator :public AbstractCalculator 
//{
//	int getResult()
//	{
//		return m_Num1 + m_Num2;
//	}
//};
//class SubCalculator :public AbstractCalculator
//{
//	int getResult()
//	{
//		return m_Num1 - m_Num2;
//	}
//};
//class MulCalculator :public AbstractCalculator
//{
//	int getResult()
//	{
//		return m_Num1 * m_Num2;
//	}
//};
//void test02() 
//{
//	//��̬ʹ������
//	//����ָ���������ָ���������\
//	
//	//�ӷ�����
//	AbstractCalculator* abc = new AddCalculator;
//	abc->m_Num1 = 100;
//	abc->m_Num2 = 10;
//	cout << abc->getResult() << endl;
//	//�����ǵ�����
//	delete abc;
//	//��������
//	abc = new SubCalculator;
//	abc->m_Num1 = 100;
//	abc->m_Num2 = 10;
//	cout << abc->getResult() << endl;
//	delete abc;
//	//�˷�����
//	abc = new MulCalculator;
//	abc->m_Num1 = 100;
//	abc->m_Num2 = 100;
//	cout << abc->getResult() << endl;
//	delete abc;
//	
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