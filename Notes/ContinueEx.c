#include <stdio.h>
main()
{
	int i=1;
	while (i <= 10)
	{
		if (i == 5)
		{
			i++;
			continue;
		}
		printf("%d ",i);
		i++;
	}
}
