//Pointers and Arrays
#include <stdio.h>
main()
{
	int n[5],i,sum=0,*p;
	printf("Enter 5 values\n");
	for(i=0;i<5;i++) 
	   scanf("%d",&n[i]);
	p = n;//n contains the base address
	for(i=0;i<5;i++)
	{
		sum = sum + *p;
		p++;
	}
	printf("sum = %d",sum);
}
