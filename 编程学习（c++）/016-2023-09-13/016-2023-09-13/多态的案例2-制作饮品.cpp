//#include <iostream>
//using namespace std;
////多态的案例2-制作饮品
//class AbstractDrinking 
//{
//public:
//	//煮水
//	virtual void Boil() = 0;
//	//冲泡
//	virtual void Brew() = 0;
//	//倒入杯中
//	virtual void PourCup() = 0;
//	//加入辅料
//	virtual void PutSomething() = 0;
//	//制作饮品
//	void makeDrink()
//	{
//		Boil();
//		Brew();
//		PourCup();
//		PutSomething();
//	}
//};
////制作咖啡
//class Coffee :public AbstractDrinking 
//{
//public:
//	//煮水
//	virtual void Boil() 
//	{
//		cout << "煮农夫山泉" << endl;
//	}
//	virtual void Brew() 
//	{
//		cout << "冲泡咖啡" << endl;
//	}
//	//倒入杯中
//	virtual void PourCup() 
//	{
//		cout << "倒入杯中" << endl;
//	}
//	//加入辅料
//	virtual void PutSomething() 
//	{
//		cout << "加入牛奶" << endl;
//	}
//	//制作饮品
//	
//};
//class Tea :public AbstractDrinking 
//{
//public:
//	//煮水
//	virtual void Boil()
//	{
//		cout << "煮农夫山泉" << endl;
//	}
//	virtual void Brew()
//	{
//		cout << "冲泡咖啡" << endl;
//	}
//	//倒入杯中
//	virtual void PourCup()
//	{
//		cout << "倒入杯中" << endl;
//	}
//	//加入辅料
//	virtual void PutSomething()
//	{
//		cout << "加入黄糖" << endl;
//	}
//};
//void doWork(AbstractDrinking* abs)
//{
//	abs->makeDrink();
//	delete abs;//释放
//}
//void test01() 
//{
//	//制作咖啡
//	doWork(new Coffee);//AbstractDrinking* abs = new Coffee
//	
//}
//void test02() 
//{
//	doWork(new Tea);//AbstractDrinking* abs = new Tea
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