#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    
    int f=0;
    
    for(int i=2;i*i<n;i++)
	{
		if(n%i==0)f=1;
	} 
    
    if(!f)printf("%d is a prime number.",n);
	else printf("%d is not a prime number.",n);

    return 0;
}
