//#include <iostream>
//using namespace std;
////全局函数做友元
//class Biulding 
//{
//	friend void goodGay(Biulding* biulding);
//	//goodGay全局函数是building好朋友，可以访问Biulding中私有成员
//	//不需要写在public里面，卸载类的最上面就可以了
//public:
//	Biulding() 
//	{
//		m_settingroom = "客厅";
//		m_bedroom = "卧室";
//	}
//public:
//	string m_settingroom;//客厅
//private:
//	string m_bedroom;
//
//};
//void goodGay(Biulding* biulding) 
//{ 
//	cout << "好基友全局函数，正在访问 ： " << biulding->m_settingroom << endl;
//	cout << "好基友全局函数，正在访问 ： " << biulding->m_bedroom << endl;
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