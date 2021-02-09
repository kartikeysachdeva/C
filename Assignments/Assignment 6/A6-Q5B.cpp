/*
b)
		*
		* *
		* * *
		* * * *
		* * * * *
		* * * *
		* * *
		* *
		*
*/
#include<stdio.h>
main()
{
	int i,j,x;
	printf("Enter a number: ");
	scanf("%d", &x);
	for(i=1; i<=x; i++){
		for (j=1; j<=i; j++){
			
			printf("*");
		}
		printf("\n");
	}
	for(i=x-1; i>=1; i--){
		for (j=1; j<=i; j++){
			
			printf("*");
		}
		printf("\n");
	}
}
