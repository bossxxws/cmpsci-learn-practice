//#include <iostream>
//using namespace std;
////抽象不同零件类
////抽象CPU类
//class CPU 
//{
//public:
//	virtual void calculate() = 0;
//};
////抽象显卡类
//class VideoCard 
//{
//public:
//	virtual void display() = 0;
//};
//class Memory 
//{
//public:
//	virtual void storage() = 0;
//};
//class Computer 
//{
//public:
//	Computer(CPU* cpu, VideoCard* vc, Memory* mem) 
//	{
//		m_cpu = cpu;
//		m_vc = vc;
//		m_mem = mem;
//
//	}
//	void work()
//	{
//		//让零件工作起来，调用接口
//		m_cpu->calculate();
//		m_vc->display();
//		m_mem->storage();
//	}
//	~Computer() 
//	{
//		if (m_cpu != NULL)
//		{	
//			cout << "析构零件cpu" << endl;
//			delete m_cpu;
//			m_cpu = NULL;
//		}
//		if (m_vc != NULL)
//		{
//			cout << "析构零件vc" << endl;
//			delete m_vc;
//			m_vc = NULL;
//		}
//		if (m_mem != NULL)
//		{
//			cout << "析构零件mem" << endl;
//			cout << "正在关机" << endl;
//			delete m_mem;
//			m_mem = NULL;
//		}
//	}
//private:
//	CPU* m_cpu;//cpu零件指针
//	VideoCard* m_vc;//显卡零件指针
//	Memory* m_mem;//内存零件指针                                                                                  
//};
//class intelCPU :public CPU 
//{
//public:
//	virtual void calculate() 
//	{
//		cout << "intel's CPU is working" << endl;
//	}
//};
//class intelVideoCard :public VideoCard 
//{
//public:
//	virtual void display() 
//	{
//		cout << "intel's vc is displaying" << endl;
//	}
//	
//};
//class intelMemory :public Memory 
//{
//public:
//	virtual void storage() 
//	{
//		cout << "intel's memory is storaging" << endl;
//	}
//};
//void test01() 
//{
//	
//	//第一台电脑零件
//	VideoCard* intelCard = new intelVideoCard;
//	CPU* intelCpu = new intelCPU;
//	Memory* intelmem = new intelMemory;
//
//	//创建第一台电脑
//	Computer* computer1 = new Computer(intelCpu, intelCard, intelmem);
//	computer1->work();
//	delete computer1;
//
//}
//
//int main()
//{
//	test01();
//	system("pause");
//
//	return 0;
//}