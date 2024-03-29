//#include <iostream>
//using namespace std;
//#include<fstream>
//#include<string>
////文本文件 读文件
//void test01() 
//{
//	ifstream ifs;
//	ifs.open("text.txt", ios::in);
//	if (!ifs.is_open()) //! 取反符号，判断没有打开
//	{
//		cout << "文件打开失败了" << endl;
//		return;
//	}
//	//读数据方法
//	////第一种方法
//	//char buf[1024] = { 0 };
//	////右移运算符放到buf中
//	//while (ifs >> buf) 
//	//{
//	//	cout << buf << endl;
//	//}        
//	////第二种
//	//char buf[1024] = { 0 };
//	//while (ifs.getline(buf, sizeof(buf))) 
//	//{
//	//	cout << buf << endl;
//	//}
//	////第三种方法
//	/*string buf;
//	while(getline(ifs,buf))
//	{
//		cout << buf << endl;
//	}*/
//	//第四种方法
//	char c;
//	while ((c = ifs.get()) != EOF) 
//	{
//		cout << c;
//	}
//
//
//
//	//关闭文件
//	ifs.close();
//	 
//}
//int main()
//{
//	test01();
//	system("pause");
//
//	return 0;
//}