#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>
class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) 
	{
		if (intervals.size() == 1) 
		{
			return intervals;
		}
		
		for (vector<vector<int>>::iterator it = intervals.begin(); it != intervals.end(); it++)
		{
			for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++) 
			{
				if((intervals[it][vit] <= ))
			}
		}
		//����һ�����ݴ�������ϲ�������鲢����
		vector<vector<int>> ret;
	}
};
class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals)
	{
		if (intervals.size() == 1)
		{
			return intervals;
		}
		int n = intervals.size();
		//���������򣨱Ƚϵ��ǵ�һ��Ԫ�ش�С��
		sort(intervals.begin(), intervals.end());
		//����һ�����ݴ�������ϲ�������鲢����
		vector<vector<int>> ret;
		ret.push_back(intervals[0]);
		int i = 0;
		for (int j = i + 1; j < n; j++) 
		{
			if (ret[i][1] >= intervals[j][0]) 
			{
				ret[i][1] = max(intervals[j][1], ret[i][1]);
			}
			else 
			{
				ret.push_back(intervals[j]);
				i++;
			}
		}
		return ret;
		
	}
};

int main()
{

	system("pause");

	return 0;
}