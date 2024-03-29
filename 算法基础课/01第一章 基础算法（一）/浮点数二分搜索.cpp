#include<iostream>
using namespace std;
//float binary search template
//example : get the quadratic root of x
double binarysearch(double x)
{
	double l=0,r=x;
	while(r-l>=1e-8)
	{
		double mid=(l+r)/2;
		if(mid*mid>=x)r=mid;
		else l=mid;
	}
	return r;
}
int main()
{
	double n;
	cin>>n;
	double k =binarysearch(n);
	cout<<k;
	return 0;
}
