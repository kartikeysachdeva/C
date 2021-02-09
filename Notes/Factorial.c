#include <stdio.h>
main()
{
	int n,i,f=1;
	printf("Enter a Number ");
	scanf("%d",&n);
	for(i=n;i>=1;i--)
		f = f * i;
	printf("Factorial = %d",f);
}
/*
Enter a Number 5 (n=5,f=1)
f=f*i=1*5=5
f=f*i=5*4=20
f=f*i=20*3=60
f=f*i=60*2=120
f=f*i=120*1=120
Factorial = 120
*/
