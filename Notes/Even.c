#include <stdio.h>
main()
{
	int i=1;
	while (i <= 100)
	{
		if (i % 2 == 0)
			printf("%d ",i);
		i++;
	}
}
/*
output
------
2 4 6 8 10 ... 98 100

*/
