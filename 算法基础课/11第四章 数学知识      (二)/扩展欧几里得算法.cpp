//������
//��������������a��b��һ����������x��y��ʹ��ax+by=��a��b�������Լ��һ����С���ű�ʾ��
// a��b�����Լ��Ҳ��a��b�ܴճ�������С��������




#include<bits/stdc++.h>

using namespace std;

/*

int gcd(int a,int b)
{
	return b?gcd(b,a%b)!a;
} 

*/

int exgcd(int a,int b,int &x,int &y)//ax+by=d
{
	if(!b)
	{
		x=1,y=0;
		return a;
	}
	
	int d=exgcd(b,a%b,y,x);
	
	//(a,b)=(b,a mod b)
	//by+��a mod b��x = d��
	//a mod b = a - |a/b|*b    ��|a/b|��ʾ����ȡ����
	
	//���ֲ���λ���еĵ�ʽ��ϵ����һ��λ��*������λ�ü��ϵڶ���λ��*���ĸ�λ��=���Լ��
	//��ʱ��b�൱��a��a mod b�൱��b
	//y�൱��x��x�൱��y
	//ax+by=d--->by+(a mod b)x=(a,b)
	
	y=y-a/b*x;
	
	return d;
}


int main()
{
    int n;
    cin>>n;
    
    while(n--)
    {
    	int a,b,x,y;//(x��y��ʼ����0)
    	cin>>a>>b;
    	
    	exgcd(a,b,x,y);
    	
    	cout<<x<<" "<<y<<endl;
    }
    
    
    return 0;
}
