#include<iostream>

#include<vector>

#include<algorithm>

using namespace std;


//二分求出x对应的离散化的值
int find(int x)
{
	int l=0,r=alls.size()-1;
	while(l<r)
	{
		int mid=l+r >>1;
		if(alls[mid]>=x)r=mid;
		else l=mid;
	}
	return r+1;//映射到1，2，.........n 
} 
	
int main()
{
	
	//以下是常用的写法 
	vector<int> alls;//存储所有待离散化的值
	sort(alls.begin(),alls.end());//对数组进行排序 
	alls.erase(unique(alls.begin(),alls.end()),alls.end());//去掉重复元素 
	
	return 0;
}
