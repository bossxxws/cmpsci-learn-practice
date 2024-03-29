//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int star = 0;//借以用来表示数组第一个元素
//	int end = (sizeof(arr) / sizeof(arr[0])-1);//总数除以单个求出数组的元素个数，减去一来表示最后一个数字
//	int x = 0;
//	
//	while (star<end )
//	{
//		
//		x = arr[star];
//		arr[star] = arr[end];
//		arr[end] = x;
//		star++; 
//		end--;
//	}
//	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) 
//	{
//		cout << arr[i] << endl;
//	}
//	system("pause");
//
//	return 0;
//}
