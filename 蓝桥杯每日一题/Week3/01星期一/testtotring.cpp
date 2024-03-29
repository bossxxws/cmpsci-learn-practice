#include<bits/stdc++.h>

using namespace std;

string transform(int x)
{
	string s="";
	while(x)
	{
		s+=char(x%10-48); 
		//char tmp=t-'48';
		x/=10;
	}
	return s;
}

int main()
{
	int a=123456;
	vector<int>res(1,1);
	
	//for(auto t:res)
	//{
	//	cout<<t<<endl;
	//}
	cout<<'a'-0;
	int t=123;
        string st="";
        while(t){
            st+=char(t%10);
            t/=10;
        }//日期数字转字符串
        cout<<st;
	//string s=transform(a);
	//cout<<s;
	//cout<<char(1)<<endl;
	//string s=to_string(a);
	//这里dev用不了
	
	//自己写一个转string 函数
	 
	return 0;
} 
