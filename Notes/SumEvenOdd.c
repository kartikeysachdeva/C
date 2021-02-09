#include <stdio.h>
main()
{
	int n=1,sumEven=0,sumOdd=0;
	while (n <= 100)
	{
		if (n % 2 == 0)
			sumEven = sumEven + n;
		else
			sumOdd = sumOdd + n;
		n++;
	}
	printf("Sum of Even Numbers = %d\n",sumEven);
	printf("Sum of Odd Numbers = %d",sumOdd);
}
