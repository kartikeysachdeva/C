#include <stdio.h>
main()
{
	int n1,n2,n3;
	printf("Enter three numbers ");
	scanf("%d%d%d",&n1,&n2,&n3);
	if (n1 > n2 && n1 > n3)
		printf("Big = %d",n1);
	else
		if (n2 > n3)
			printf("Big = %d",n2);
		else
			printf("Big = %d",n3);
}
