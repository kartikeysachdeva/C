/*
WAP to display the following output
	
	--------------------
	 Number   Factorial  
	--------------------
	   1          1
	   2          2
	   3          6
	   4         24
	   5        120
	--------------------
	    Sum  =  153
	---------------------
	*/

#include<stdio.h>
main()
{
	int num; 
	printf("Enter a number = ");
	scanf("%d", &num);
	printf("--------------------\n");
	printf(" Number   Factorial \n");
	printf("--------------------\n");
	int i,j,x,sum=0,fact=1;
	
	
	for(i=1;i<=num;i++){
		fact*=i;
		sum+=fact;
		printf("   %d   	     %d\n", i, fact);
		}
		
	

	
	
	printf("--------------------\n");
	printf("    Sum  =  %d      \n", sum);
	printf("--------------------\n");
	
	
}
