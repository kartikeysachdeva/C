#include<stdio.h>
main()
{
	int i,j,a[3][3]={
				{1,2,3},
				{4,5,6},
				{7,8,9},
				};
	for(i=0;i<=2;i++){
		for(j=0;j<=2;j++){
			printf("%d", a[i][j]);
		}
		printf("\n");
	}
	printf("After transpose\n");
	for(i=0;i<=2;i++){
		for(j=0;j<=2;j++){
			
			printf("%d", a[j][i]);
		}
		printf("\n");
	}
	
	printf("Multiplication");
	for(i=0; i<3;i++)
	
}
