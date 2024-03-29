//#include <iostream>
//using namespace std;
//#include<string>;
////设计人类
//class Person 
//{
//public:
//	//设置姓名 可读可写
//	void setName(string name)
//	{
//		Name = name;
//	}
//	//获取姓名
//	string getName()
//	{
//		return Name;
//	}
//	//获取年龄 只读
//	int getAge()
//	{
//		int Age = 0;
//		return Age;
//	}
//	int setAge(int age) 
//	{	
//		if (age < 0 || age >150) 
//		{	
//			age = 0;
//			cout << "年龄不合理" << endl;
//			return;
//		}
//		Age = age;
//	}
//	//设置情人 只写
//	void setlover(string lovername)
//	{
//		Lover = lovername;
//	}
//
//
//	//写姓名
//	//读姓名
//private:
//	//姓名
//	string  Name;
//	int Age;
//	string Lover;
//};
//int main()
//{
//	Person p;
//	p.setName("李晨洋");
//	cout <<"姓名为:"<< p.getName() << endl;
//	cout << "年龄为： " << p.getAge() << endl;
//	p.setlover("曼曼");//只有内部可以获取到，外部无法访问
//
//
//	system("pause");
//
//	return 0;
//}