#include<iostream>

#include<vector>

#include<algorithm>

using namespace std;


//�������x��Ӧ����ɢ����ֵ
int find(int x)
{
	int l=0,r=alls.size()-1;
	while(l<r)
	{
		int mid=l+r >>1;
		if(alls[mid]>=x)r=mid;
		else l=mid;
	}
	return r+1;//ӳ�䵽1��2��.........n 
} 
	
int main()
{
	
	//�����ǳ��õ�д�� 
	vector<int> alls;//�洢���д���ɢ����ֵ
	sort(alls.begin(),alls.end());//������������� 
	alls.erase(unique(alls.begin(),alls.end()),alls.end());//ȥ���ظ�Ԫ�� 
	
	return 0;
}
