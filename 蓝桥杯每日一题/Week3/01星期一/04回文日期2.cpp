#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>

using namespace std;
int months[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
bool check(int date) //判断日期是否合法
{
    int year = date / 10000;
    int month = date % 10000 / 100;
    int day = date % 100;
    if(!day || month < 0 || month > 12 ) return false;
    if(month != 2 && day >months[month]) return false;
    if(month == 2)
    {
        if((year%4==0&&year%100!=0)||(year%400==0)) //闰年特判
        {
            if(day > 29) return false;
        }
        else 
        {
            if(day > 28) return false;
        }
    }
    return true;
}
bool check1(string s)  //判断是否是回文日期
{
    int len = s.size();
    for(int i = 0, j = len - 1; i < j ; i++,j--)  //双指针
    {
        if(s[i] != s[j]) return false;
    }
    return true;
}
bool check2(string s)  //判断是否是ABABBABA 型的回文日期
{
    if(check1(s))  //首先该日期要满足回文格式
    {
       if(s[0]!=s[2] || s[1]!= s[3] || s[0] == s[1]) return false;
       return true;
    }
    return false;
}
int main()
{
    int date,flag=0;
    cin>>date;
    for(int i = date + 1; ;i++)
    {
        if(check(i))
        {
            string s = to_string(i);
            if(check1(s)&&!flag)   //输出回文日期
            {
                cout<<i<<endl;
                flag = 1;  //标记一下，避免多次输出
            }
            if(check2(s))  //输出ABABBABA 型的回文日期
            {
                cout<<i<<endl;
                return 0;
            }
        }
    }
    return 0;
}

