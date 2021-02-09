#include <stdio.h>
main()
{
	int n=1;
	while (n <= 10)
	{
		if (n % 2 == 0)
		{
			printf("%d,",n);
			if (n < 10)
			 printf(", ");
		}
		
		n++;
	}
}
