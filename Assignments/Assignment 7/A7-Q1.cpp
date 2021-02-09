#include<stdio.h>
main()
{
	int i,n[10], num, count=0;
	printf("Enter 10 numbers : ");
	for(i=0; i<10; i++){
		scanf("%d", &n[i]);
	}
	for(i=0;i<10; i++){
		printf("%d ", n[i]);
	}
	printf("\nKey: ");
	scanf("%d", &num);
	for(i=0; i<10; i++)
	{
		if(n[i]==num){
			count++;
		}
	}
	printf("Frequency of %d is %d", num, count);
	
}
