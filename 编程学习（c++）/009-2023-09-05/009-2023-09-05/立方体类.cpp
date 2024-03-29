#include <iostream>
using namespace std;
//创建立方体类
//设置属性和行为
//获取立方体的面积和体积
//分别利用全局函数和成员函数判断两个立方体是否相等
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
	//获取立方面积
	int S()
	{
		int s;
		s = 2 * (L * W + W * H+H*L);
		return s;

	}
	//体积
	int V()
	{	
		int v;
		v = L * W * H;
		return v;
	}
	//利用成员函数判断是否相等
	bool same(cube &c) 
	{
		if (c.getW() == W && c.getH() == H);
	}

private:
	int L;
	int W;
	int H;

};
bool isSame(cube c1,cube c2)//取不取地址均可
{
	if (c1.getW() == c2.getW() && c1.getH() == c2.getH()) 
	{
		return true;
	}
	return false;
}
int main()
{
	//创建立方体对象
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
		cout << "相等" << endl;
	}
	else 
	{
		cout << "不相等" << endl;
	}


	
	system("pause");

	return 0;
}