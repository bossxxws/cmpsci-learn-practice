#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	double x;
	cin>>x;
	double l=-100000,r=100000;
	while(r-l>1e-8)
	{
		double mid=(r+l)/2;
		if(mid*mid*mid>x)r=mid;
		else l=mid;
	}
	cout << fixed << setprecision(6) << r << endl;
	return 0;
}
