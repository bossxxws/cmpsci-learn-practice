//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int star = 0;//����������ʾ�����һ��Ԫ��
//	int end = (sizeof(arr) / sizeof(arr[0])-1);//�������Ե�����������Ԫ�ظ�������ȥһ����ʾ���һ������
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
