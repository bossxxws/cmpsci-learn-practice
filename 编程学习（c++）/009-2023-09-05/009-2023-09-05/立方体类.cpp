#include <iostream>
using namespace std;
//������������
//�������Ժ���Ϊ
//��ȡ���������������
//�ֱ�����ȫ�ֺ����ͳ�Ա�����ж������������Ƿ����
class cube
{
public:
	void setL(int l)
	{
		L = l;

	}
	int getL()
	{
		return L;
	}
	void setW(int w)
	{
		W = w;
	}
	int getW()
	{
		return W;
	}
	void setH(int h)
	{
		H = h;
	}
	int getH()
	{
		return H;
	}
	//��ȡ�������
	int S()
	{
		int s;
		s = 2 * (L * W + W * H+H*L);
		return s;

	}
	//���
	int V()
	{	
		int v;
		v = L * W * H;
		return v;
	}
	//���ó�Ա�����ж��Ƿ����
	bool same(cube &c) 
	{
		if (c.getW() == W && c.getH() == H);
	}

private:
	int L;
	int W;
	int H;

};
bool isSame(cube c1,cube c2)//ȡ��ȡ��ַ����
{
	if (c1.getW() == c2.getW() && c1.getH() == c2.getH()) 
	{
		return true;
	}
	return false;
}
int main()
{
	//�������������
	cube c1;
	c1.setH(10);
	c1.setL(10);
	c1.setW(10);
	cout << c1.S()<<" "<< c1.V() << endl;
	cube c2;
	c2.setH(5);
	c2.setL(5);
	c2.setW(5);
	if (isSame(c1, c2)) 
	{
		cout << "���" << endl;
	}
	else 
	{
		cout << "�����" << endl;
	}


	
	system("pause");

	return 0;
}