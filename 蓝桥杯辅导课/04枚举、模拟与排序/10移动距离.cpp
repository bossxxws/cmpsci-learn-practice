#include<bits/stdc++.h>

using namespace std;

int w,n,m; 

int getcol(int x,int l)
{
	int c;
	//if(l==2)cout<<" "<<x<<endl;
	if(l%2==0)//ż�� ���� 
	{
	    //if(l==2)cout<<" "<<l<<endl;
		c=w-(x-w*(l-1))+1;
		//if(l==2)cout<<" "<<x<<endl;
		//if(l==2)cout<<" "<<c<<endl;
	}
	else//���� ���� 
	{
		c=x-w*(l-1);
	}
	return c;
}

int main()
{
	cin>>w>>n>>m;
	
	//wΪҪ�źŵĿ�ȣ�n��mΪҪѯ�ʵı��
	/*
	
	1  2  3   4  5  6 
	
	12 11 10  9  8  7
		
	13 14 15 16 17 18
	
	19 20 21 22 23 24
	
	30 29 28 27 26 25
	
	��������������ż���е���
	 ������������+1 
	*/
	int l1=0,l2=0;
	int a=n,b=m;
	while(n>w)
	{
	    l1++;
	    n-=w;
	}
	while(m>w)
	{
	    l2++;
	    m-=w;
	}
	l1++;
	l2++;
	int c1=getcol(a,l1);
	int c2=getcol(b,l2);
	//cout<<l1<<" "<<l2<<endl;
	//cout<<c1<<" "<<c2<<endl;
	//cout<<l1<<" "<<c1<<endl;
	//cout<<l2<<" "<<c2<<endl;
	cout<<abs(l1-l2)+abs(c1-c2)<<endl; 
	
	return 0;
}
