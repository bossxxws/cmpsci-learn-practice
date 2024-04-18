#include<bits/stdc++.h>

using namespace std;

priority_queue<int,vector<int>,greater<int>> q;//Ð¡¸ù¶Ñ 

int main()
{
	q.push(2);
	q.push(3);
	q.push(1000);
	
	cout<<q.top();
	
	return 0;
} 
