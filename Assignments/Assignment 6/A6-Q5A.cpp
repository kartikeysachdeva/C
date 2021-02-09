/*WAP to display the following patterns

	a)
		1
		2 3
		4 5 6
		7 8 9 10
*/

#include<stdio.h>
main()
{
	int i,j,x,count= 1;
	printf("Enter a number: ");
	scanf("%d", &x);
	for(i=1; i<=x; i++){
		for (j=1; j<=i; j++){
			
			printf("%d", count);
			count++;
		}
		printf("\n");
	}
}
