//#include <iostream>
//using namespace std;
////����ͬ�����
////����CPU��
//class CPU 
//{
//public:
//	virtual void calculate() = 0;
//};
////�����Կ���
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
//		//������������������ýӿ�
//		m_cpu->calculate();
//		m_vc->display();
//		m_mem->storage();
//	}
//	~Computer() 
//	{
//		if (m_cpu != NULL)
//		{	
//			cout << "�������cpu" << endl;
//			delete m_cpu;
//			m_cpu = NULL;
//		}
//		if (m_vc != NULL)
//		{
//			cout << "�������vc" << endl;
//			delete m_vc;
//			m_vc = NULL;
//		}
//		if (m_mem != NULL)
//		{
//			cout << "�������mem" << endl;
//			cout << "���ڹػ�" << endl;
//			delete m_mem;
//			m_mem = NULL;
//		}
//	}
//private:
//	CPU* m_cpu;//cpu���ָ��
//	VideoCard* m_vc;//�Կ����ָ��
//	Memory* m_mem;//�ڴ����ָ��                                                                                  
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
//	//��һ̨�������
//	VideoCard* intelCard = new intelVideoCard;
//	CPU* intelCpu = new intelCPU;
//	Memory* intelmem = new intelMemory;
//
//	//������һ̨����
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