#include<stdio.h>
main()
{
	int n,sum, temp, count=0; 
	printf("Enter a number ");
	scanf("%d", &n);
	while(n>0){
		n=n/10;
		count++;
	}
	while(n>0){
		temp=n%10;
		n=n/10;
		sum= temp^count;
	}
	if(n==sum){
		printf("This is an Armstrong number");
	}
	else{
		printf("This is not an Armstrong number");
	}
}
