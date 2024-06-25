/*
����ṹ�е����Ա�������ʽ

��Ӧ���д��룺���ݽṹ�㷨��Ӧ��c++����

�����д���ȿ���Ƥ

��дʱ�䣺2020��6��24�� 13:51:23

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
	LinearList(int MaxListSize ); //���캯��Ĭ��Ϊ
	~LinearList();                    //��������
	LinearList(const LinearList<T> & L);  //���ƹ��캯��
	bool IsEmpty()const;              //�ж��Ƿ�Ϊ��
	int Length() const { return length; }  //���ر�ĳ��ȣ�������Ԫ�ظ��� 
	bool Find(int k, T& x)const; //���ص�k��Ԫ����x�� �������ڵ�k��Ԫ�أ��򷵻�false
	int Search(const T& x) const; // ����x����λ�� ���x ���ڱ��У��򷵻�0
	LinearList<T>& Delete(int k, T& x); // ɾ����k��Ԫ�ز�����������x��
	LinearList<T>& Insert(int k, const T& x); // �ڵ�k��Ԫ��֮�����x
	//�ı�������󳤶Ⱥ�����lΪ���鳤�ȣ�mΪ������󳤶�
	LinearList<T>& changeSize(T * elementNew, int nlength, int max); 
	LinearList<T>& Reverse();  //Ԫ�ش���ķ�ת element[k]=element[length-k]
	LinearList<T>& Half();  //�������
	void Reset() { current = 1; } //��������λ
	bool Current(T &x);     //���ص�ǰ��ֵ
	bool End()const;       //�Ƿ�Ϊ����
	bool Front() const;   //�Ƿ�Ϊ��ǰ��
	void Next();        //���¸�ֵ
	void Previous();    //��ǰһ��ֵ
	void clear();
	//���Ա������
	LinearList<T>& Alternate(const LinearList<T> & list1, const LinearList<T> & list2);
	//�й��ɣ�Ԫ�ش�С�������У����Ա�����
	LinearList<T>& Merge(const LinearList<T> & list1, const LinearList<T> & list2);
	//���Ա�ָ��
	void Split(LinearList<T> & list1, LinearList<T> & list2);

	void Output(ostream& out) const; // �������
	LinearList<T> & operator =(const LinearList<T> & x); //���ظ�ֵ����
private:
	int length;   //����ĳ���
	int MaxSize;  //�������ֵ
	T * element; //һά��̬����
	int current;  //Ԫ�ص�ǰ��λ��
};

template<class T>
inline LinearList<T>::LinearList()
{
	MaxSize = 1;
	element = new T[MaxSize];
	length = 0;
}

//���캯��Ĭ��Ϊ10
template<class T>
LinearList<T>::LinearList(int MaxListSize)
{
	MaxSize = MaxListSize;
	element = new T[MaxSize];
	length = 0;
}

//��������
template<class T>
LinearList<T>::~LinearList()
{
	delete[] element;  
}

//���ƹ��캯��
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

//�ж��Ƿ�Ϊ��
template<class T>
bool LinearList<T>::IsEmpty() const
{
	return 0 == length;
}

//���ص�k��Ԫ����x�� �������ڵ�k��Ԫ�أ��򷵻�false
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

// ���Һ���  ����x����λ�� ���x ���ڱ��У��򷵻�0
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

//ɾ������
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
//��������
//�ڵ�k��Ԫ��֮�����x�����������޸ĺ�����Ա�
template<class T>
LinearList<T>& LinearList<T>::Insert(int k, const T & x)
{
	//�ڵ�k��Ԫ��֮�����x�����������޸ĺ�����Ա�
	//��������ڵ�k��Ԫ�أ��������쳣OutOfBound
	//������Ѿ������������쳣NoMem
	if (k<0 || k > length)
	{
		throw OutOfBounds();
	}
	if (length == MaxSize)
	{
		throw Noman();
	}
	//����ƶ�һλ ���������Ǽ�һ ��д����
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


//�ı��С����ʡ�ռ�
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

//���ݷ�ת����
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
	 //�������ַ�����д����Ҳ�ǽ�ָoffer�е�֪ʶ��  
	 //����1
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
	 //��������ֱ�����ù��캯���������Ͳ����Լ�дdelete�ˣ�����Ͳ���¼��
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


 //���Խ��溯��
 template<class T>
 LinearList<T>& LinearList<T>::Alternate(const LinearList<T>& list1, const LinearList<T>& list2)
 {
	 //���Խ��� 
	 if (length>0)
	 {
		 delete[] element; //���ԭ������
	 }
	 length = list1.length + list2.length;
	 element = new T[length]; 
//	 MaxSize = length;
	 LinearList<T> A = list1, B = list2; //���ƹ��캯��
	 A.Reset();
	 B.Reset();
	 int value = 0; //��¼��ǰλ�õ�ֵ
	 int minLenght = A.length <= B.length ? A.length: B.length; //��ȡ��ǰ�Ƚ�С��ֵ

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
		 if (A.End() || B.End())  //�жϵ�ǰ�Ƿ�Ϊ���һ��
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
		 //�жϲ��ǽ�β
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
	 element = new T[length]; //�����µı�ǩ

	 int ca = 0, cb = 0, ct = 0;
	 //���Ķ��е�����
	 while (ca < list1.length && cb < list2.length)
	 {
		 if (list1.element[ca] >= list2.element[cb])
		 {
			 element[ct++] = list2.element[cb++];
		 }
		 else
			 element[ct++] = list1.element[ca++];
	 }
	 //����ʣ�µ�����
	 if (ca == list1.length) //��ʾlist1����������
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


//�͵ط�ת�������ö���
template<class T>
void ReverseEle(LinearList<T> & data)
{
	data.Reverse();
}


//�����б�����
void testLinearList()
{
	try
	{
		//����Ϊ�յ�ʱ��
		cout << "��ʼ����ʼ" << endl;
		LinearList<int> L;
		cout << "Lenght = " << L.Length() << endl;
		cout << "IsEmpty = " << L.IsEmpty() << endl;

		L.Insert(0, 2);
		L.Insert(1, 6);
		//Ҳ��������д
		L.Insert(2, 5).Insert(3, 4).Insert(4, 8);
		cout << "List is " << L << endl;
		cout << "isEmpty " << L.IsEmpty() << endl;

		//���Բ��뺯��
		L.Insert(1, 10).Insert(2,1);
		cout << "List is " << L << endl;
		cout << "isEmpty " << L.IsEmpty() << endl;
		cout << "lengh is " << L.Length()<< endl;
		int z;
		L.Find(1, z); //�ҵ���һ����������
		cout << "first element " << z << endl;
		cout << "Lenght = " << L.Length() << endl;
		cout << "lengh is " << L.Length() << endl;

		L.Delete(1, z);
		cout << "Deleted element is " << z << endl;
		cout << "List is " << L << endl;
		cout << "lengh is " << L.Length() << endl;

		cout << endl;
		//���Բ���
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
		
		//��ת����
		for (int i = 0; i<500000; i++)
		{
			L.Insert(i, i);
		}
		cout << L.Length() << endl;
		clock_t  startTime, stopTime;
		startTime = clock();
		L.Reverse();
		stopTime = clock();

		cout << "���Ա��תʹ�õ�ʱ�䣺 " << float(stopTime - startTime) / CLK_TCK << endl;

		//�͵ط�ת
		startTime = clock();
		ReverseEle(L);
		stopTime = clock();
		cout << "�͵ط�תʹ�õ�ʱ�䣺 " << float(stopTime - startTime) / CLK_TCK << endl;

		//����half
		L.Half();
		cout << "length is : " << L.Length()<< endl;

		//���Ը��ƹ��캯��
		LinearList<int> ML(L);
		cout << "length L is : " << L.Length() << endl;
		cout << "length ML is : " << ML.Length() << endl;

		//����current����
		ML.Reset(); //λ����0

		//����next
		ML.Next(); //�ƶ����¸�λ��
		cout << "�ж��Ƿ���ǰ�ߵ� " << ML.Front() << endl;
		int value = 0;
		cout << "��ǰ�Ƿ������� ��" << ML.Current(value) << endl;
		cout << "�����ǰ��ֵ�� ��" << value << endl;
		//������������Ҳ����ͬ��

		//���Խ�������
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
		cout << "C is list ��" << C << endl;
		//���Ժϲ�����ǰ�ᶼ��˳���
		A.Insert(4, 10);
		LinearList<int> D;
		D.Merge(A,B);
		cout << "D is list ��" << D << endl;

		//����
		A.clear();
		B.clear();
		D.Split(A,B);
		cout << "D is list ��" << D << endl;
		cout << "A is List : " << A << endl;
		cout << "B is List : " << B << endl;


	}
	catch (const std::exception&)
	{
		cerr << "An exception has occurred" << endl;
	}
}

