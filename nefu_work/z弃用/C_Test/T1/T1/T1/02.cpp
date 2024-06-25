#include <stdio.h>

int main(void)
{
	char a[4] = "210";
	int b[3]; int* p1; char* p2;
	b[0] = 2;
	b[1] = 1;
	b[2] = 0;
	printf("%x£¬%x\n", &a, &b);
	p2 = &(a[2]); p1 = &(b[1]);
	*p2 = *p2 + 2;
	p2 = p2 - 2;
	printf("%s\n", a);
	printf("%d\n", *p1);
	printf("%c\n", *p2);
	return 0;
}