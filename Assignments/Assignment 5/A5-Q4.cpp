#include<stdio.h>
main()
{
	int n,temp=0,sum=0; 
	printf("Enter a number ");
	scanf("%d", &n);
	while(n>0){
		temp=n%10;
		n=n/10;
		if(temp%2==0){
			sum+=temp;
		}
	}
	printf("Sum= %d", sum);
		
}
