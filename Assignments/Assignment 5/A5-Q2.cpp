#include <stdio.h>
main()
{
	int palin, n,rev=0;
	printf("Enter a Number ");
	scanf("%d",&n);
	palin=n;
	while (n != 0)
	{
		rev = rev * 10 + n % 10;
		n = n / 10;
	}
	if(rev == palin){
		printf("This number is palindrome number");
	}
	else
	printf("This is not palindrome number");
}
