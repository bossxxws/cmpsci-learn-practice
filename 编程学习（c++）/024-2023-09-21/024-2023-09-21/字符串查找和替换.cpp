//#include <iostream>
//using namespace std;
//
////字符串查找和替换
////查找
//void test01() 
//{
//	string str1 = "abcdefgde";
//	int pos = str1.find("de");//输出为第三个索引  如果没有这个字串，返回-1
//	if (pos == -1) 
//	{
//		cout << "未找到字符串" << endl;
//
//	}
//	else 
//	{
//		cout << "找到字符串" << endl;
//		cout << pos << endl;
//	}
//	//rfind
//	pos = str1.rfind("de");//rfind是从右往左查找，find是从左往右查找
//	cout << pos << endl;
//
//	
//
//}
//
////替换
//void test02() 
//{
//	string str1 = "abcdefg";
//	str1.replace(1, 3, "1111");//从1索引开始，三个字符替换为1111
//	cout << str1 << endl;
//}
//
//
//int main()
//{
//	test01();
//	test02();
//	system("pause");
//
//	return 0;
//}