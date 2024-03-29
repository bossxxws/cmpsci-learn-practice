//#include <iostream>
//using namespace std;
//
////类模板与继承
//template<class T>
//class Base 
//{
//public:
//	T m;
//};
////class Son:public Base 报错
//class Son :public Base<int>
//{
//	
//};
//void test01() 
//{
//	Son s1;
//}
////如果想灵活的指定父类中T的类型，那么子类也要变为一个类模板
//template<class T1,class T2>
//class Son2 :public Base<T2>
//{
//public:
//	Son2() 
//	{
//		cout << "T1的类型为 " << typeid(T1).name() << endl;
//		cout << "T2的类型为 " << typeid(T2).name() << endl;
//	}
//	T1 obj;
//};
//void test02() 
//{
//	Son2<int, char>S2;
//}
//int main()
//{
//	test02();
//	system("pause");
//
//	return 0;
//}