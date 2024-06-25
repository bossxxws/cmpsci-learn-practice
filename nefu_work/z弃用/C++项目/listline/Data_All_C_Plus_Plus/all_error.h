/*
线性表中的数组结构

对应书中代码：数据结构算法与应用c++描述

程序编写：比卡丘不皮

编写时间：2020年6月24日 13:51:23

*/
#pragma once

#include <iostream>
using namespace std;

class Noman
{
public:
	Noman()
	{
		cout << "内存不足"<< endl;
	}
	~Noman()
	{

	}
};

//使new引发NoMemory异常而不是xalloc异常

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
		cout << "超出范围" << endl;
	}
	~OutOfBounds()
	{

	}
};


