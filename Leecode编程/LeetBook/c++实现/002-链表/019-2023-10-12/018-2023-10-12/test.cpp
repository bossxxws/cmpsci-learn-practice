#include <iostream>
using namespace std;

#include<iostream>
using namespace std;
int main()
{
    cout << "This is my first C++ program in Linux!!" << endl;
    int a = 0;
    int b = 1;
    int add(int x, int b)
    {
        return x + b;
    }
   
    int k = add(a, b);
    cout << k << endl;
    return 0;
}