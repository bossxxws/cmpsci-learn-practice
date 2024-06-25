#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<stack>
vector<int> toleft(int n) 
{
	vector<int>res;
	int cou = 1;
	int one;
	int two;
	int three;
	int four;
	int five;
	int six;
	while (n > 0) 
	{
		int tem = n % 10;
		if (cou == 1) five = tem;
		if (cou == 2) four = tem;
		if (cou == 3) three = tem;
		if (cou == 4) two = tem;
		if (cou == 5) one = tem;
		if (cou == 6) six = tem;
		cou++;
		n = n / 10;
	}
	res.push_back(one);
	res.push_back(two);
	res.push_back(three);
	res.push_back(four);
	res.push_back(five);
	res.push_back(six);
	return res;
}
int main() 
{
	int x;
	cin >> x;
	vector<int>res = toleft(x);
	for (auto ele : res) 
	{
		cout << ele;
	}
	return 0;
}