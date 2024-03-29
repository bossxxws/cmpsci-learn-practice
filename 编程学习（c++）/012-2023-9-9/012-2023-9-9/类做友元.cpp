#include <iostream>
using namespace std;
class Building ;
class GoodGay 
{
public:
	GoodGay();
	//参观函数访问building中的属性
	void visit();

	Building* building;
};
class Building 
{
	friend class GoodGay;
public:
	Building();
public: 
	string m_sittigroom;//客厅

private:
	string m_bedroom;
};
//类外写成员函数
Building::Building() 
{
	 m_sittigroom= "客厅";
	 m_bedroom = "卧室";

}
GoodGay::GoodGay() 
{
	building = new Building;
}
void GoodGay::visit() 
{
	cout << "好基友类正在访问： " << building->m_sittigroom << endl;
	cout << "好基友类正在访问： " << building->m_bedroom << endl;
}
void test01() 
{
	GoodGay gg;
	gg.visit();
}

int main()
{
	test01();
	system("pause");

	return 0;
}