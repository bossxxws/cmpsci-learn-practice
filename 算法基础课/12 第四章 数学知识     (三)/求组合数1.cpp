//ʮ����ѯ�� 1<=a<=b<=2000 ʹ�õ��� 

//cab=a��/��b��*��a-b������
//��ͨ�����һ��һ����ÿ�ζ�Ҫ����һ��ʱ�临�ӶȺܸߣ�ʮ���ѯ�ʣ� 
//������ǰ������еģ�ʡ�����ʮ���ѯ��ÿ�ζ�һ��һ���� 

//ͨ������ʽ�� 
//Cab=C(a-1)b+C(a-1)(b-1)
//��ʼ��sһ�����鴢������Cab�����������ʱ�临�Ӷ� 

//ʱ�临�Ӷȣ�N**2 
#include<bits/stdc++.h>

using namespace std;

const int N = 2010,mod=1e9+7;

int c[N][N];

void init()
{
	for(int i=0;i<N;i++)
		for(int j=0;j<=i;j++)
			if(!j)c[i][j]=1;
			else c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
			//i-1�Ѿ���ȫ����ʼ��������˵������������ 
}

int main()
{
	init();
	
	int n;
	cin>>n;
	
	while(n--)
	{
		int a,b;
		cin>>a>>b;
		cout<<c[a][b]<<endl;
	}
	
	
	return 0;
}
