//自己通用的数组类
#pragma once
#include<iostream>
using namespace std;

template<class T>
class MyArray 
{

public:
	//有参构造  参数：容量（能存储元素的最大值）
	MyArray(int Capacity) 
	{
		cout << "有参构造调用" << endl;
		this->m_Capacity = Capacity;
		this->m_Size = 0;//size表示当前的存储的元素数量
		this->pAddress = new T[this->m_Capacity];//开辟连续的空间存储T类型的元素
	}

	//拷贝构造
	//（数组之间可以拷贝，并且不出错）
	MyArray(const MyArray& arr)//arr是被拷贝对象
	{
		cout << "拷贝构造调用" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//this->pAddress = arr.pAddress
		
		//深拷贝
		this->pAddress = new T[this->m_Capacity];

		//将arr中的数据都拷贝过来
		for (int i = 0; i < this->m_Size; i++) 
		{
			this->pAddress[i] = arr.pAddress[i];
		}

	}

	//重新定义赋值符号（数组之间赋值不出错）
	//operate= 防止浅拷贝问题    
	//a=b=c MyArray&，*this等号赋值返回自身，能进行连等的操作
	MyArray& operator=(const MyArray& arr) 
	{
		cout << "等号调用" << endl;
		//先判断原来堆区是否有数据
		if (this->pAddress != NULL) 
		{
			delete[] this->pAddress;
			//为什么要加中括号？
			//因为当我们使用 new 运算符动态分配一个数组时：
			//应该使用 delete[] 运算符来释放这个数组所占用的内存空间。
			//这是因为 new 和 delete 操作符需要匹配使用
			//而动态分配的数组使用了 new[] 运算符
			//因此在释放内存时应该使用 delete[] 运算符。
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;

		}
		//深拷贝
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[this->m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;


	}

	//尾插法
	void Push_Back(const T &val) //为什么不能直接用T？
	{
		//判断容量是否等于大小
		if (this->m_Capacity == this->m_Size) 
		{
			cout << "容量已满！" << endl;
			return;
		}
		else 
		{
			this->pAddress[this->m_Size] = val;//在数组末尾插入数据
			this->m_Size++;//更新数组大小
		}
	}

	//尾删法
	void Pop_Back() 
	{
		//让用户访问不到最后一个元素，就是尾删法
		if (this->m_Size == 0) 
		{
			return;
		}
		this->m_Size --;
	}

	//通过下标的方式访问数组中的元素
	
	//重载[]以便其能访问自定义的数组
	T& operator[](int index) 
	//如果函数调用想作为等号的左值存在 arr[0] = 100；
	//要返回T的引用才行
	//为什么？
	{
		return this->pAddress[index];
	}

	//返回数组容量
	int getCapacity()
	{
		return this->m_Capacity;
	}
	//返回数组大小

	int getSize() 
	{
		return this->m_Size;
	}
	

	//析构函数
	~MyArray() 
	{
		if (this->pAddress != NULL) 
		{
			cout << "析构调用" << endl;
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}

	
private:
	T* pAddress;//指针指向堆区开辟的真实的数组

	int m_Capacity;

	int m_Size;
};