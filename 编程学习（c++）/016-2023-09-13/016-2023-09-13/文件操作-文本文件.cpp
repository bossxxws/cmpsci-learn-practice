#include <iostream>
using namespace std;
#include<fstream>//头文件包含
// 文本文件 写文件
void test01() 
{
	//1·包含头文件fstream
	//2·创建流对象
	ofstream ofs;//o输出，f文件，stream流，往文件输出，就是写文件
	//3·指定打开方式
	ofs.open("text.txt", ios::out);
	//4·写内容
	ofs << "姓名：李晨洋" << endl;
	ofs << "妻子：曼曼，曹睿鸣" << endl;
	//5·关闭文件
	ofs.close();
}
int main()
{
	test01();

	system("pause");

	return 0;
}