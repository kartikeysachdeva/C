/*  WAP to find area of a circle
	float pi = 3.14;
		area = pi * radius * radius;
*/
#include<stdio.h>
main()
{
	float r, area;
	const float pi= 3.14;
	
	printf("Enter radius: ");
	scanf("%f", &r);
	
	area= pi*r*r;
	printf("Area of circle is: %.2f", area);
	
	retun 0; 
}
