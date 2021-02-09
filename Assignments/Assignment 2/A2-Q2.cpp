//WAP to check whether the given year is leap year or not
#include<stdio.h>
main(){
	int year; 
	printf("Enter year: ");
	scanf("%d", &year);
	if(year%4==0 && year%100!=0){
		printf("This is a leap year");
	}
	else{
		printf("This is not a leap year");
	}
}
