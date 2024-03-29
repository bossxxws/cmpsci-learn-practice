#include <iostream>
using namespace std;
#include<string>
#define Max 1000
//构造联系人结构体
struct person
{
	string Name;
	string Sex;
	int Age;
	string Phone;
	string Address;

};
struct Addressbook {
	struct person personArry[Max]; 
	int Size;
};
//显示菜单
void showMenu() 
{
	cout << "***********************" << endl;
	cout << "*****1、添加联系人*****" << endl;
	cout << "*****2、显示联系人*****" << endl;
	cout << "*****3、删除联系人*****" << endl;
	cout << "*****4、查找联系人*****" << endl;
	cout << "*****5、修改联系人*****" << endl;
	cout << "*****6、清空联系人*****" << endl;
	cout << "*****0、退出通讯录*****" << endl;
	cout << "***********************" << endl;
}
//添加联系人
void Addperson(Addressbook * Black) //Black指针访问Addressbook中的对象
{
	if (Black->Size == Max) 
	{	
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else 
	{
		string name;
		cout << "请输入姓名:  " << endl;
		cin >> name;
		Black->personArry[Black->Size].Name = name; 
		cout << "请输入性别: " << endl;
		cout << "输入------男  " << endl;
		cout << "或者------女  " << endl;
		string sex;
		while (true)
		{
			cin >> sex;
			if (sex == "男" || sex == "女" )
			{
				Black->personArry[Black->Size].Sex = sex;
				break;
			}
		}
		cout << "请输入年龄：" << endl;
		int age;
		cin>> age;
		Black->personArry[Black->Size].Age = age;
		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		Black->personArry[Black->Size].Phone = phone;
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		Black->personArry[Black->Size].Address = address;
		Black->Size++;//更新通讯录中的人数
		cout << "添加成功" << endl;
		system("pause");
		system("cls");			
	}
	
}
//显示联系人
void showPerson(Addressbook * Black) 
{
	//判断通讯录有没有人
	if(Black->Size == 0)
	{
		cout << "当前记录为空" << endl;

	}
	else 
	{
		for (int i = 0; i < Black->Size; i++) 
		{
			cout << "  姓名  ："     <<Black->personArry[i].Name << "\t";
			cout << "  性别  ："     << Black->personArry[i].Sex << "\t";
			cout << "  年龄  ："     << Black->personArry[i].Age << "\t";
			cout << "  电话  ："     << Black->personArry[i].Phone << "\t";
			cout << "家庭住址：" << Black->personArry[i].Address << endl;
		}
	}
	system("pause");
	system("cls");//清空屏幕
}
//删除联系人-检测联系人是否存在，如果存在，返回联系人具体位置，不存在返回-1
//检测联系人是否存在
int isExist(Addressbook * Black,string cinname) //调用时，应该传递指向 Addressbook 结构体的指针作为参数，而不是解引用之后的对象。
{
	for (int i = 0; i < Black->Size; i++) 
	{
		if (Black->personArry[i].Name == cinname) 
		{
			return i;
		}
	}
	return -1;

}
//删除联系人
void deletePerson(Addressbook * Black)
{
	cout << "请输入要删除的联系人的姓名" << endl;
	string cinname;
	cin >> cinname;
	int ret = isExist(Black, cinname);
	if (ret != -1) 
	{
		for (int i = ret; i < Black->Size; i++) 
		{
			//数据前移
			Black->personArry[i] = Black->personArry[i + 1];
		}
		Black->Size--;//更新通讯录的人数
		cout << "删除联系人： " << cinname << " 成功" << endl;
	}
	else 
	{
		cout << "查无此人 " << endl;
	}
	system("pause");
	system("cls");//清空屏幕
}
//查找指定联系人
void findPerson(Addressbook * Black) 
{
	cout << "输入你要查找的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(Black,name);
	if (ret != -1)
	{
		cout << "找到联系人：" << endl;
		cout << "     姓名：" << Black->personArry[ret].Name << "\t";
		cout << "     性别：" << Black->personArry[ret].Sex  << "\t";
		cout << "     年龄：" << Black->personArry[ret].Name << "\t";
		cout << "     电话：" << Black->personArry[ret].Phone << "\t";
		cout << "     家庭住址：" << Black->personArry[ret].Address << endl;
	}
	else 
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");	
}
//修改联系人
void modifyPerson(Addressbook* Black) 
{
	cout << "Please input the name:" << endl;
	string name;
	cin >> name;
	int ret = isExist(Black, name);
	if (ret != -1)
	{
		string Newname;
		cout << "Please input the Newname:";
		cin >> Newname;
		string NewSex;
		cout << "Please input the NewnSex:";
		cin >> NewSex;
		int NewAge;
		cout << "Please input the NewAge:";
		cin >> NewAge;
		cout << "Please input the NewPhone:";
		string NewPhone;
		cin >> NewPhone;
		cout << "Please input the NewAddress:";
		string NewAddress;
		cin >> NewAddress;
		Black->personArry[ret].Name = Newname;
		Black->personArry[ret].Sex = NewSex;
		Black->personArry[ret].Age = NewAge;
		Black->personArry[ret].Phone = NewPhone;
		Black->personArry[ret].Address = NewAddress;
		cout << "---------已成功修改联系人---------" << endl;
		cout << "-------------当前信息-------------" << endl;
		cout << "       姓名：" <<  Newname << "\t";
		cout << "       性别：" <<  NewSex << "\t";
		cout << "       年龄：" <<  NewAge << "\t";
		cout << "       电话：" <<  NewPhone << "\t";
		cout << "       家庭住址：" << NewAddress << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//清空联系人
void CleanAll(Addressbook* Black) 
{
	string s;
	cout << "你确定清空所有联系人吗？输入（Yes/No）" << endl;
	cin >> s;
	if (s ==  "Yes") 
	{
		Black->Size = 0;
		cout << "----------所有联系人已清空----------" << endl;

	}
	system("pause");
	system("cls");
}

//菜单的调用
int main()
{	
	int select = 0;//创建用户选择输入的变量	
	Addressbook Black;
	Black.Size = 0;
	while (true) 
	{	
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1://1、添加联系人
			Addperson(&Black);//只写Black是值传递，要写地址才能修饰数据
			break;
		case 2://2、显示联系人
			showPerson(&Black);
			break;
		case 3://3、删除联系人
			deletePerson(&Black);
			break;
		case 4://4、查找联系人
			findPerson(&Black);
			break;
		case 5://5、修改联系人
			modifyPerson(&Black);
			break;
		case 6://6、清空联系人
			CleanAll(&Black);
			break;
		case 0://0、退出通讯录
			cout << "欢迎下次使用" << endl;
			return 0;
			break;
		default:
			break;
		}	
	}
	system("pause");
	return 0;
}
//传递对象的地址（&Black）：
//函数参数的类型应该是指向 Addressbook 对象的指针（Addressbook* ）或者更通用的指针类型（如 void* ）。
//通过指针可以直接修改 Addressbook 对象的内容。
//可以避免对整个对象进行拷贝，节省内存和时间。
//在函数内部对对象进行修改后，调用者将看到对象的更改，因为它们引用的是同一个对象。
//传递对象本身（Black）：
//函数参数的类型应该是 Addressbook 对象类型（Addressbook）。
//在函数内部对对象进行修改时，实际上是对传入对象的副本进行操作，不会影响原始对象。
//可能会产生额外的内存开销，特别是当对象较大时，因为需要进行对象的拷贝。
//对象的修改仅在函数内部可见，调用者看到的对象仍然是原始的、未修改的对象。


