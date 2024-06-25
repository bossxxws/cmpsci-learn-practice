/*
数组结构中的线性表数组样式

对应书中代码：数据结构算法与应用c++描述

程序编写：比卡丘不皮

编写时间：2020年6月24日 13:51:23

*/
#pragma once
#include <iostream>
#include "all_error.h"
#include <ctime>
using namespace std;

template<class T>
class LinearList
{
public:
	LinearList();
	LinearList(int MaxListSize ); //构造函数默认为
	~LinearList();                    //析构函数
	LinearList(const LinearList<T> & L);  //复制构造函数
	bool IsEmpty()const;              //判断是否为空
	int Length() const { return length; }  //返回表的长度，即表中元素个数 
	bool Find(int k, T& x)const; //返回第k个元素至x中 若不存在第k个元素，则返回false
	int Search(const T& x) const; // 返回x所在位置 如果x 不在表中，则返回0
	LinearList<T>& Delete(int k, T& x); // 删除第k个元素并将它返回至x中
	LinearList<T>& Insert(int k, const T& x); // 在第k个元素之后插入x
	//改变数组最大长度函数，l为数组长度，m为数组最大长度
	LinearList<T>& changeSize(T * elementNew, int nlength, int max); 
	LinearList<T>& Reverse();  //元素次序的反转 element[k]=element[length-k]
	LinearList<T>& Half();  //数组减半
	void Reset() { current = 1; } //设置数据位
	bool Current(T &x);     //返回当前的值
	bool End()const;       //是否为最后边
	bool Front() const;   //是否为最前边
	void Next();        //到下个值
	void Previous();    //到前一个值
	void clear();
	//线性表交叉组合
	LinearList<T>& Alternate(const LinearList<T> & list1, const LinearList<T> & list2);
	//有规律（元素从小到大排列）线性表的组合
	LinearList<T>& Merge(const LinearList<T> & list1, const LinearList<T> & list2);
	//线性表分割函数
	void Split(LinearList<T> & list1, LinearList<T> & list2);

	void Output(ostream& out) const; // 输出函数
	LinearList<T> & operator =(const LinearList<T> & x); //重载赋值运算
private:
	int length;   //数组的长度
	int MaxSize;  //数组最大值
	T * element; //一维动态数组
	int current;  //元素当前的位置
};

template<class T>
inline LinearList<T>::LinearList()
{
	MaxSize = 1;
	element = new T[MaxSize];
	length = 0;
}

//构造函数默认为10
template<class T>
LinearList<T>::LinearList(int MaxListSize)
{
	MaxSize = MaxListSize;
	element = new T[MaxSize];
	length = 0;
}

//析构函数
template<class T>
LinearList<T>::~LinearList()
{
	delete[] element;  
}

//复制构造函数
template<class T>
 LinearList<T>::LinearList(const LinearList<T>& L)
{
	if (this == &L)
	{
		return;
	}
	else
	{
		this->length = L.length;
		this->MaxSize = L.MaxSize;
		delete[] element;
		element = new T[length+1];
		memcpy(element, L.element, length * sizeof(T));

	}
}

//判断是否为空
template<class T>
bool LinearList<T>::IsEmpty() const
{
	return 0 == length;
}

//返回第k个元素至x中 若不存在第k个元素，则返回false
template<class T>
bool LinearList<T>::Find(int k, T & x) const
{
	if (k<1 || k>length)
	{
		return false;
	}
	else
	{
		x = element[k-1];
	}

	return true;
}

// 查找函数  返回x所在位置 如果x 不在表中，则返回0
template<class T>
int LinearList<T>::Search(const T & x) const
{
	for (int i =0; i<length; i++)
	{
		if (x == element[i])
		{
			return ++i;
		}
	}
	return 0;
}

//删除数据
template<class T>
LinearList<T>& LinearList<T>::Delete(int k, T & x)
{

	if (Find(k,x))
	{
		for (int i = k; i < length; i++)
		{
			element[i - 1] = element[i];
		}
		length--;
		if (length == (MaxSize / 4) && length > 0)
		{
			MaxSize /= 2;
			changeSize(element,length,MaxSize);
		}
		
		return *this;
	}
	else
	{
		throw  OutOfBounds();
	}
}
//插入数据
//在第k个元素之后插入x；函数返回修改后的线性表
template<class T>
LinearList<T>& LinearList<T>::Insert(int k, const T & x)
{
	//在第k个元素之后插入x；函数返回修改后的线性表
	//如果不存在第k个元素，则引发异常OutOfBound
	//如果表已经满，则引发异常NoMem
	if (k<0 || k > length)
	{
		throw OutOfBounds();
	}
	if (length == MaxSize)
	{
		throw Noman();
	}
	//向后移动一位 书中这里是减一 书写错误
	for (int i = length - 1; i >= k; i--)
	{
		element[i + 1] = element[i];
	}
	element[k] = x;
	length++;
	if (length == MaxSize)
	{
		MaxSize *= 2;
		changeSize(element, length, MaxSize);
	}

	return *this;
}


//改变大小，节省空间
template<class T>
inline LinearList<T>& LinearList<T>::changeSize(T * elementNew, int nlength, int max)
{
	element = new T[max];
	for (int i = 0; i<nlength; i++)
	{
		element[i] = elementNew[i];
	}
	delete[] elementNew;
	return *this;
}

//数据反转函数
template<class T>
 LinearList<T>& LinearList<T>::Reverse()
{
	for (int i = 0; i< (length/2); i++)
	{
		T temp = element[i];
		element[i] = element[length-1-i];
		element[length - 1 - i] = temp;
	}
	return *this;

}

 template<class T>
 LinearList<T>& LinearList<T>::Half()
 {
	 length = (length + 1) / 2;
	 //这里两种方案来写程序，也是剑指offer中的知识点  
	 //方法1
	 T *elementNew = new T[length+1];
	 for (int i = 0; i<=length; i++)
	 {
		 elementNew[i] = element[2 * i];
	 }
	 delete[] element;

	 element = new T[length+1];
	 for (int i = 0; i <= length; i++)
	 {
		 element[i] = elementNew[i];
	 }

	 delete[] elementNew;
	 return *this;
	 //方法二是直接利用构造函数，这样就不用自己写delete了，这里就不记录了
 }

 template<class T>
 bool LinearList<T>::Current(T & x)
 {
	 if (current < 0 || current > MaxSize)
	 {
		 return false;
	 }
	 else
	 {
		 x = element[current - 1];
		 return true;
	 }

 }

 template<class T>
 inline bool LinearList<T>::End() const
 {
	 return current == length;
 }

 template<class T>
 inline bool LinearList<T>::Front() const
 {
	 return current == 1;
 }

 template<class T>
 inline void LinearList<T>::Next()
 {
	 if (current < length)
	 {
		 current++;
	 }
	 else
	 {
		 throw OutOfBounds();
	 }
 }

 template<class T>
 inline void LinearList<T>::Previous()
 {
	 if (current > 1)
	 {
		 current--;
	 }
	 else
	 {
		 throw OutOfBounds();
	 }
 }

 template<class T>
  void LinearList<T>::clear()
 {
	  this->MaxSize = 1;
	  delete [] element;
	  element = new T[MaxSize];
	  this->length = 0;
 }


 //线性交叉函数
 template<class T>
 LinearList<T>& LinearList<T>::Alternate(const LinearList<T>& list1, const LinearList<T>& list2)
 {
	 //线性交叉 
	 if (length>0)
	 {
		 delete[] element; //清除原有数据
	 }
	 length = list1.length + list2.length;
	 element = new T[length]; 
//	 MaxSize = length;
	 LinearList<T> A = list1, B = list2; //复制构造函数
	 A.Reset();
	 B.Reset();
	 int value = 0; //记录当前位置的值
	 int minLenght = A.length <= B.length ? A.length: B.length; //获取当前比较小的值

	 for (int i = 0; i<minLenght;i++)
	 {
		 if (A.Current(value))
		 {
			 element[2 * i] = value;
		 }
		 
		 if (B.Current(value))
		 {
			 element[2 * i + 1] = value;
		 }
		 if (A.End() || B.End())  //判断当前是否为最后一个
		 {
			 break;
		 }
		 else
		 {
			 A.Next();
			 B.Next();
		 }
	 }

	 for (int i = 2 * minLenght; i<length; i++ )
	 {
		 //判断不是结尾
		 if (!A.End())
		 {
			 A.Next();
			 A.Current(value);
			 element[i] = value;
		 }
		 else
		 {
			 B.Next();
			 B.Current(value);
			 element[i] = value;
		 }
	 }

	 return *this;

 }

 template<class T>
 LinearList<T>& LinearList<T>::Merge(const LinearList<T>& list1, const LinearList<T>& list2)
 { 
	 if (length > 0)
	 {
		 delete[] element;
	 }
	 length = list1.length + list2.length;
	 MaxSize = length;
	 element = new T[length]; //创建新的标签

	 int ca = 0, cb = 0, ct = 0;
	 //先拍都有的数据
	 while (ca < list1.length && cb < list2.length)
	 {
		 if (list1.element[ca] >= list2.element[cb])
		 {
			 element[ct++] = list2.element[cb++];
		 }
		 else
			 element[ct++] = list1.element[ca++];
	 }
	 //在排剩下的数据
	 if (ca == list1.length) //表示list1数组排完了
	 {
		 for (int i = cb;i < list2.length;i++)
		 {
			 element[ct] = list2.element[i];
			 ct++;
		 }
	 }
	 else
	 {
		 for (int i = ca; i < list1.length; i++)
		 {
			 element[ct] = list1.element[i];
			 ct++;
		 }
	 }
	 return *this;
 }

 template<class T>

 void LinearList<T>::Split(LinearList<T>& list1, LinearList<T>& list2)
 {
	 int aNum = 0;
	 int bNum = 0;
	 for (int i = 0; i < length; i++)
	 {
		 if ((i & 1) == 0)
		 {
			 list1.Insert(aNum++, element[i]);
		 }
		 else
		 {
			 list2.Insert(bNum++, element[i]);
		 }
	 }
 }

template<class T>
void LinearList<T>::Output(ostream & out) const
{
	for (int i = 0; i < length; i++)
	{
		out << element[i] << " ";
	}
}

template<class T>
inline LinearList<T>& LinearList<T>::operator=(const LinearList<T>& x)
{
	if (this == &x)
	{
		return *this;
	}
	this->MaxSize = x.MaxSize;
	this->length = x.length;
	memcpy(element, x.element,length * sizeof(T));
}



template<class T>
ostream & operator<<(ostream & out, const LinearList<T> & x)
{
	x.Output(out);
	return out;
}


//就地反转函数利用对象
template<class T>
void ReverseEle(LinearList<T> & data)
{
	data.Reverse();
}


//测试列表数组
void testLinearList()
{
	try
	{
		//设置为空的时候
		cout << "初始化开始" << endl;
		LinearList<int> L;
		cout << "Lenght = " << L.Length() << endl;
		cout << "IsEmpty = " << L.IsEmpty() << endl;

		L.Insert(0, 2);
		L.Insert(1, 6);
		//也可以这样写
		L.Insert(2, 5).Insert(3, 4).Insert(4, 8);
		cout << "List is " << L << endl;
		cout << "isEmpty " << L.IsEmpty() << endl;

		//测试插入函数
		L.Insert(1, 10).Insert(2,1);
		cout << "List is " << L << endl;
		cout << "isEmpty " << L.IsEmpty() << endl;
		cout << "lengh is " << L.Length()<< endl;
		int z;
		L.Find(1, z); //找到第一个数的数据
		cout << "first element " << z << endl;
		cout << "Lenght = " << L.Length() << endl;
		cout << "lengh is " << L.Length() << endl;

		L.Delete(1, z);
		cout << "Deleted element is " << z << endl;
		cout << "List is " << L << endl;
		cout << "lengh is " << L.Length() << endl;

		cout << endl;
		//测试查找
		cout << "test Search" << endl;
		cout << "List is " << L << endl;
		cout << "6 in L? " << L.Search(6) << endl;
		cout << "9 in L? " << L.Search(9) << endl;

		cout << endl;
		cout << "test Reverse" << endl;
		L.Reverse();
		cout << "List is " << L << endl;
		cout << "isEmpty " << L.IsEmpty() << endl;
		cout << "lengh is " << L.Length() << endl;
		
		//反转测试
		for (int i = 0; i<500000; i++)
		{
			L.Insert(i, i);
		}
		cout << L.Length() << endl;
		clock_t  startTime, stopTime;
		startTime = clock();
		L.Reverse();
		stopTime = clock();

		cout << "类成员反转使用的时间： " << float(stopTime - startTime) / CLK_TCK << endl;

		//就地反转
		startTime = clock();
		ReverseEle(L);
		stopTime = clock();
		cout << "就地反转使用的时间： " << float(stopTime - startTime) / CLK_TCK << endl;

		//测试half
		L.Half();
		cout << "length is : " << L.Length()<< endl;

		//测试复制构造函数
		LinearList<int> ML(L);
		cout << "length L is : " << L.Length() << endl;
		cout << "length ML is : " << ML.Length() << endl;

		//测试current类容
		ML.Reset(); //位置置0

		//测试next
		ML.Next(); //移动到下个位置
		cout << "判断是否是前边的 " << ML.Front() << endl;
		int value = 0;
		cout << "当前是否有问题 ：" << ML.Current(value) << endl;
		cout << "输出当前的值是 ：" << value << endl;
		//其他函数测试也是相同的

		//测试交叉数据
		LinearList<int> A, B;
		for (int i = 0; i<4; i++)
		{
			A.Insert(i, i);
			B.Insert(i, i);
		}
		B.Insert(4, 4).Insert(5, 5);
		cout << "A is List : " << A <<endl;
		cout << "B is List : " << B <<endl;
		LinearList<int> C;
		C.Alternate(A,B);
		cout << "C is list ：" << C << endl;
		//测试合并排序，前提都是顺序的
		A.Insert(4, 10);
		LinearList<int> D;
		D.Merge(A,B);
		cout << "D is list ：" << D << endl;

		//测试
		A.clear();
		B.clear();
		D.Split(A,B);
		cout << "D is list ：" << D << endl;
		cout << "A is List : " << A << endl;
		cout << "B is List : " << B << endl;


	}
	catch (const std::exception&)
	{
		cerr << "An exception has occurred" << endl;
	}
}

