/*
���Ա��е�����ṹ

��Ӧ���д��룺���ݽṹ�㷨��Ӧ��c++����

�����д���ȿ���Ƥ

��дʱ�䣺2020��6��24�� 13:51:23

*/
#pragma once

#include <iostream>
using namespace std;

class Noman
{
public:
	Noman()
	{
		cout << "�ڴ治��"<< endl;
	}
	~Noman()
	{

	}
};

//ʹnew����NoMemory�쳣������xalloc�쳣

void my_new_handler()
{
	throw Noman();
}

new_handler Old_Handler_ = set_new_handler(my_new_handler);

class OutOfBounds
{
public:
	OutOfBounds()
	{
		cout << "������Χ" << endl;
	}
	~OutOfBounds()
	{

	}
};


