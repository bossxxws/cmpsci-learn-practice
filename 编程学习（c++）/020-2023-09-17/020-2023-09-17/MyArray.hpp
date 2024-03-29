//�Լ�ͨ�õ�������
#pragma once
#include<iostream>
using namespace std;

template<class T>
class MyArray 
{

public:
	//�вι���  �������������ܴ洢Ԫ�ص����ֵ��
	MyArray(int Capacity) 
	{
		cout << "�вι������" << endl;
		this->m_Capacity = Capacity;
		this->m_Size = 0;//size��ʾ��ǰ�Ĵ洢��Ԫ������
		this->pAddress = new T[this->m_Capacity];//���������Ŀռ�洢T���͵�Ԫ��
	}

	//��������
	//������֮����Կ��������Ҳ�����
	MyArray(const MyArray& arr)//arr�Ǳ���������
	{
		cout << "�����������" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//this->pAddress = arr.pAddress
		
		//���
		this->pAddress = new T[this->m_Capacity];

		//��arr�е����ݶ���������
		for (int i = 0; i < this->m_Size; i++) 
		{
			this->pAddress[i] = arr.pAddress[i];
		}

	}

	//���¶��帳ֵ���ţ�����֮�丳ֵ������
	//operate= ��ֹǳ��������    
	//a=b=c MyArray&��*this�ȺŸ�ֵ���������ܽ������ȵĲ���
	MyArray& operator=(const MyArray& arr) 
	{
		cout << "�Ⱥŵ���" << endl;
		//���ж�ԭ�������Ƿ�������
		if (this->pAddress != NULL) 
		{
			delete[] this->pAddress;
			//ΪʲôҪ�������ţ�
			//��Ϊ������ʹ�� new �������̬����һ������ʱ��
			//Ӧ��ʹ�� delete[] ��������ͷ����������ռ�õ��ڴ�ռ䡣
			//������Ϊ new �� delete ��������Ҫƥ��ʹ��
			//����̬���������ʹ���� new[] �����
			//������ͷ��ڴ�ʱӦ��ʹ�� delete[] �������
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;

		}
		//���
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[this->m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;


	}

	//β�巨
	void Push_Back(const T &val) //Ϊʲô����ֱ����T��
	{
		//�ж������Ƿ���ڴ�С
		if (this->m_Capacity == this->m_Size) 
		{
			cout << "����������" << endl;
			return;
		}
		else 
		{
			this->pAddress[this->m_Size] = val;//������ĩβ��������
			this->m_Size++;//���������С
		}
	}

	//βɾ��
	void Pop_Back() 
	{
		//���û����ʲ������һ��Ԫ�أ�����βɾ��
		if (this->m_Size == 0) 
		{
			return;
		}
		this->m_Size --;
	}

	//ͨ���±�ķ�ʽ���������е�Ԫ��
	
	//����[]�Ա����ܷ����Զ��������
	T& operator[](int index) 
	//���������������Ϊ�Ⱥŵ���ֵ���� arr[0] = 100��
	//Ҫ����T�����ò���
	//Ϊʲô��
	{
		return this->pAddress[index];
	}

	//������������
	int getCapacity()
	{
		return this->m_Capacity;
	}
	//���������С

	int getSize() 
	{
		return this->m_Size;
	}
	

	//��������
	~MyArray() 
	{
		if (this->pAddress != NULL) 
		{
			cout << "��������" << endl;
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}

	
private:
	T* pAddress;//ָ��ָ��������ٵ���ʵ������

	int m_Capacity;

	int m_Size;
};