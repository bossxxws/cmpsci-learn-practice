#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>

using namespace std;
int months[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
bool check(int date) //�ж������Ƿ�Ϸ�
{
    int year = date / 10000;
    int month = date % 10000 / 100;
    int day = date % 100;
    if(!day || month < 0 || month > 12 ) return false;
    if(month != 2 && day >months[month]) return false;
    if(month == 2)
    {
        if((year%4==0&&year%100!=0)||(year%400==0)) //��������
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
bool check1(string s)  //�ж��Ƿ��ǻ�������
{
    int len = s.size();
    for(int i = 0, j = len - 1; i < j ; i++,j--)  //˫ָ��
    {
        if(s[i] != s[j]) return false;
    }
    return true;
}
bool check2(string s)  //�ж��Ƿ���ABABBABA �͵Ļ�������
{
    if(check1(s))  //���ȸ�����Ҫ������ĸ�ʽ
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
            if(check1(s)&&!flag)   //�����������
            {
                cout<<i<<endl;
                flag = 1;  //���һ�£����������
            }
            if(check2(s))  //���ABABBABA �͵Ļ�������
            {
                cout<<i<<endl;
                return 0;
            }
        }
    }
    return 0;
}

