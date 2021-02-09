#include <stdio.h>
main()
{
	int n=10,y,*p;
	p = &n;
	printf("%d is stored at address %u\n",n,p);
	y = *p;
	printf("y = %d\n",y);
	*p = *p + 10;
	printf("n = %d\n",n);
}
/*
output
------
10 is stored at address 2291336
y = 10
n = 20
*/
