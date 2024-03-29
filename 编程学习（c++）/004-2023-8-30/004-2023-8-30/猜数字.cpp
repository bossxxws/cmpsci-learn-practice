//#include <iostream>
//using namespace std;
//
//int main()
//{
//	srand(time(NULL)); //随机数种子初始化，获得"真正的"随机数
//	int f = 0;
//	int a = rand()%100 + 1;
//	cout << "请输入你猜测的数字" << endl;
//	cin >> f;
//	cout << "您猜测数字为：" << f << endl;
//	while (a != f)
//	{
//		if (a > f)
//		{
//			cout << "您输入的数字偏小" << endl;
//			cout << "请输入你猜测的数字" << endl;
//			cin >> f;
//		}
//		else 
//		{
//			cout << "您输入的数字偏大" << endl;
//			cout << "请输入你猜测的数字" << endl;
//			cin >> f;
//		}	
//	}
//	cout << "恭喜您猜中了！" << endl;
//	system("pause");
//
//	return 0;
//	
//}