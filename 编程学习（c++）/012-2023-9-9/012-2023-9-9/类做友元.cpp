#include <iostream>
using namespace std;
class Building ;
class GoodGay 
{
public:
	GoodGay();
	//�ιۺ�������building�е�����
	void visit();

	Building* building;
};
class Building 
{
	friend class GoodGay;
public:
	Building();
public: 
	string m_sittigroom;//����

private:
	string m_bedroom;
};
//����д��Ա����
Building::Building() 
{
	 m_sittigroom= "����";
	 m_bedroom = "����";

}
GoodGay::GoodGay() 
{
	building = new Building;
}
void GoodGay::visit() 
{
	cout << "�û��������ڷ��ʣ� " << building->m_sittigroom << endl;
	cout << "�û��������ڷ��ʣ� " << building->m_bedroom << endl;
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