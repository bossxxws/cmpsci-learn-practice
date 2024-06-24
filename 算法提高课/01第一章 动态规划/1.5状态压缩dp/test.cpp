#include<bits/stdc++.h>

using namespace std;

void swap2(int* i, int* j);
void rank(int* x, int* y);

int main() {
   int val1 = 15, val2 = 13;
   printf("%d %d\n", val1, val2);
   ///rank(&val1, &val2);
   printf("%d %d\n", val1, val2);
   char *x;
	char y;
	char z[4]=	"abc";
	x=z;
	y=z[2];
	z[0]=*(x+1);
	cout<<"---"<<endl;
	cout<<*z<<" "<<z[0]<<endl;
	cout<<"---"<<endl;

}

void swap2(int* i, int* j) {
  int temp;
  temp = *i;
  *i = *j;
  *j = temp;
}

void rank(int* x, int* y) 
{
  int swaped = 0;
  if(*x > *y){
      swap2(x, y);
      swaped = 1;
  }
}
