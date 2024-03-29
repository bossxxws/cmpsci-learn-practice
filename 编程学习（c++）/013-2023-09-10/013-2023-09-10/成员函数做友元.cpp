//#include <iostream>
//using namespace std;
//class Building;
//class goodgay 
//{
//public:
//	goodgay();
//	
//	void visit1();//让visit1函数可以访问building中的私有成员
//	void visit2();//让visit2函数不可以访问building中的私有成员
//	Building* building;
//
//};
//class Building
//{	
//	//告诉编译器，googday下的visit成员作为本类的好朋友，
//	friend void goodgay::visit1();//goodgay类下的成员函数作为本类的好朋友，可以访问私有成员
//
//public:
//	Building();
//public:
//	string sittingroom;
//private:
//	string bedroom;
//
//
//
//};
//Building::Building() 
//{
//	sittingroom = "客厅";
//	bedroom = "卧室";
//
//}
//goodgay::goodgay() 
//{
//	building = new Building;
//}
//void goodgay::visit1() 
//{
//	cout << "正在访问： " << building->sittingroom << endl;
//	cout << "正在访问： " << building->sittingroom << endl;
//	cout << "正在访问： " << building->bedroom << endl;
//
//}
//void goodgay::visit2() 
//{
//	cout << "正在访问： " << building->sittingroom << endl;
//
//}
//void test01() 
//{
//	goodgay gg;
//	gg.visit1();
//	
//
//}
//int main()
//{
//	test01();
//
//	system("pause");
//
//	return 0;
//}