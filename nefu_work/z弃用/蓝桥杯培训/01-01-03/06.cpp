/*
Description
QWQ������һ������ĵط�������ط��кܶ���ɫ��ͬ�Ĳ�ɫʯ��ÿ����ɫ��������һ�����������棬QWQ�ռ���һ��ʯ�ӣ�����֪�����ʯ������ɫ��ͬ��ʯ�Ӹ��������ֵ
Input
��1������һ������n���������ʯ�ӵĸ���
�ڶ�������n����������n��ʯ�ӵ���ɫ 
��֤�������������������100
Output
���һ�����֣�������ɫ��ͬ��ʯ�Ӹ��������ֵ
Sample Input
10
1 3 5 7 9 1 2 3 5 5
Sample Output
3
*/
#include<bits/stdc++.h>

using namespace std;

const int N=1e5;
int ar[N];

int main()
{
	int res=0;
	int n;
	cin>>n;
	int arr[n];
	
	for(int i=0;i<n;i++)cin>>arr[i];
	
	
	for(int i=0;i<n;i++)
	{
		ar[arr[i]]++;
		if(ar[arr[i]]>res)res=ar[arr[i]];
	}
	cout<<res;
	return 0;
}
