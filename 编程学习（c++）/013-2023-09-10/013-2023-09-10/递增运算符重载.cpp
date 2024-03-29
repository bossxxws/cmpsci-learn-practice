//#include <iostream>
//using namespace std;
////重载递增运算符
////自定义整型
//class MyInteger 
//{
//	friend ostream& operator<< (ostream& cout, MyInteger myint);
//public:
//	MyInteger() 
//	{
//		m_Num = 0;
//	}
//	//重载++运算符--前置++运算符  返回引用是为了一直对一个数据进行操作
//	MyInteger& operator++() 
//	{
//		m_Num ++;
//		return *this;
//	}
//	//重载++运算符--后置++运算符
//	//void operator++(int) int代表占位参数，可以用于区分前置递增和后置递增，占位参数用int，其他的float ，double不好使
//	MyInteger& operator++(int)
//	{
//		
//		//记录一下当时结果
//		MyInteger temp = *this;
//		
//		//后递增
//		
//		m_Num++;
//		//最后将记录的结果返回
//		return temp;
//
//	}
//private:
//	int m_Num;
//};
////重载左移运算符 ---原因是输出的是我们自定义的对象，编译器不知道里面是什么，不知道怎么输出，输出什么
//ostream& operator<< (ostream& cout, MyInteger myint) //本质operator <<（cout,p）; 简化cout<<p;
//{
//
//	cout << myint.m_Num;
//	return cout;
//
//}
//
//void test01() 
//{
//	MyInteger myint;
//	//必须重载++运算符，因为编译器不知道怎么该对自定义的数据类型进行递增运算
//	cout << ++myint << endl;
//	cout << ++(++myint) << endl;
//
//}
//void test02() 
//{
//	MyInteger myint;
//	cout << myint++ << endl;
//	cout << myint << endl;
//
//}
//
//int main()
//{
//	test01();
//	test02();
//	system("pause");
//
//	return 0;
//}
