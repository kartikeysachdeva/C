#include<stdio.h>
main()
{
	int n[10]= {1,2,3,2,7,8,9,6,5,4};
		int i,j, num, count=0, biggest=0, smallest=n[1], biggest2, smallest2;
	for(i=0;i<10; i++){
		printf("%d ", n[i]);
	}
	for(i=0; i<10; i++)
	{
		if(biggest<n[i]){
			biggest=n[i];
		}
	}
	
	for(i=0; i<10; i++)
	{
		if(smallest>n[i]){
			smallest=n[i];
		}
	}
	printf("\nBiggest = %d", biggest);
	printf("\nSecond Biggest = %d", biggest2);
	printf("\nSmallest = %d", smallest);
	
}
