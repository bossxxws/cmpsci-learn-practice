//#include <iostream>
//using namespace std;
//class Building;
//class goodgay 
//{
//public:
//	goodgay();
//	
//	void visit1();//��visit1�������Է���building�е�˽�г�Ա
//	void visit2();//��visit2���������Է���building�е�˽�г�Ա
//	Building* building;
//
//};
//class Building
//{	
//	//���߱�������googday�µ�visit��Ա��Ϊ����ĺ����ѣ�
//	friend void goodgay::visit1();//goodgay���µĳ�Ա������Ϊ����ĺ����ѣ����Է���˽�г�Ա
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
//	sittingroom = "����";
//	bedroom = "����";
//
//}
//goodgay::goodgay() 
//{
//	building = new Building;
//}
//void goodgay::visit1() 
//{
//	cout << "���ڷ��ʣ� " << building->sittingroom << endl;
//	cout << "���ڷ��ʣ� " << building->sittingroom << endl;
//	cout << "���ڷ��ʣ� " << building->bedroom << endl;
//
//}
//void goodgay::visit2() 
//{
//	cout << "���ڷ��ʣ� " << building->sittingroom << endl;
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