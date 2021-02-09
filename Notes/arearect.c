//to find area of rectangle using functions
#include <stdio.h>
main()
{
	int length, breadth,area;
	printf("Enter length and breadth values ");
	scanf("%d%d",&length,&breadth);//10 5
	area = arearect(length,breadth);
	printf("Area of Rectangle = %d",area);
}
int arearect(int length,int breadth)
{
	int area;
	area = length * breadth;
	return area;
}
