#include<stdio.h>
main()
{
	int x=2,y=1,sumOdd=0,sumEven=0,finalSum=0;
	
	while (x<=100 && x%2==0)
	{
		sumEven=sumEven+x;
		x+=2;
	} 
	while (y<=100 && y%2==1){
		sumOdd=sumOdd+y;
		y+=2;
	}
	printf("Odd sum= %d\n Even sum= %d\n", sumOdd, sumEven);
	finalSum= sumOdd+sumEven;
	printf("Final Sum= %d", finalSum);
}
