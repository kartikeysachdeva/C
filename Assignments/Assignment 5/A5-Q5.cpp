#include<stdio.h>
main()
{
	int x,n,temp=0,sum=0; 
	printf("Enter a number ");
	scanf("%d", &n);
	
	while (n>9){
		sum=0;
	while(n>0){
		temp=n%10;
		n=n/10;
		sum+=temp;
	}	
	n=sum;
	
}
	printf("%d",sum);	
}
