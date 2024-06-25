#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int recursion(int n)
{
	if (n <= 0)
		n = 0; 
	else if (n == 1)
		n = 1; 
	else
		n = n * recursion(n - 1) - 1; 
	return n ;
}
	int main() {
		int n;
		scanf_s("%d", &n);
		printf("%d", recursion(n));

		return 0;
	}