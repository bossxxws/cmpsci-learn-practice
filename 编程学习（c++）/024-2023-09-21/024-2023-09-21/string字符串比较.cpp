//#include <iostream>
//using namespace std;
//
////字符串比较
////比的是阿斯克码值
//
//void test01() 
//{
//	string str1 = "hello";
//	string str2 = "xello";
//
//	if (str1.compare(str2) == 0) //返回值是0的话是相等---最大的用途
//	//对比的是阿斯克码值，逐个对比，判断阿斯克码值大小，对比大小的话意义不大
//	//最重要的用途就是判断是否相等
//	{
//		cout << "str1 等于 str2" << endl;
//	}
//	else if (str1.compare(str2) > 0)//返回值大于0则字符串大于被比的字符串
//	{
//		cout << "str1 大于 str2" << endl;
//	}
//	else if (str1.compare(str2) < 0)//返回值小于0则字符串小于被比的字符串
//	{
//		cout << "str1 小于 str2" << endl;
//	}
//	
//
//}
//
//int main()
//{
//	test01();
//
//	system("pause");
//
//	return 0;
//}