#include <iostream>
using namespace std;
class person 
{
public:
//	person(int a, int b, int c) 
//	{
//		int m_A = a;
//		int m_B = b;
//		int m_C = c;

	/*}*/
	person(int a, int b, int c) :m(a), n(b), k(c) {}
	void pint()
	{
		cout << "personone" <<": "<< m << endl;
	}
private:
	int m;
	int n;
	int k;



};


int main()
{
	person p(45, 2, 3);
	p.pint();

	system("pause");

	return 0;
}