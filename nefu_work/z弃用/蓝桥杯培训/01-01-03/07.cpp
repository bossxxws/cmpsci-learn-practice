/*
Description
����ACMУ���õ��˺����Ƽ���С���ֽ�Ʒ��������30��ˮ���������������Ľ�Ʒ���࣬��Ҳ��Ҫ��л�����̵ģ�
����ˮ���ǼӼ����Ƶģ���������ˮ���ĵĹ��̺�������ͬ���Ӷ�������ˮ���ĸ߶Ⱦ�Ȼ�ǲ�һ���ģ�
�涨ˮ���߶ȵ���20.00CM Ϊ���ϸ�Ĳ�Ʒ�����ܼ���һ������ˮ���ĺϸ�����
Input
���ⵥ�����ݣ�
�������ݵ�һ��Ϊn����ʾˮ��������������������n��ˮ���ĸ߶ȣ�ʵ������
Output
�������ˮ���ĺϸ��ʣ�����2λС�������ϸ���=�ϸ�����/����
Sample Input
5
19.23 18.00 21.00 22.00 20.00
Sample Output
0.60
*/
#include<bits/stdc++.h>

using namespace std;

int main()
{
	double good=0;
	int total;
	cin>>total;
	double arr[total];
	for(int i=0;i<total;i++)cin>>arr[i];
	for(int i=0;i<total;i++)
	{
		if(arr[i]>=20.00)
		{
			good++;
		}
	}
	double res=good/total;
	cout<<fixed<<setprecision(2)<<res;
	return 0;
}
