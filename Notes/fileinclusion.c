#include "mylib.h" //for user defined header file we need use " "
main()
{
	int length,breadth,radius;
	printf("Enter length and breadth values ");
	scanf("%d%d",&length,&breadth);
	printf("Area of Rectangle = %d",arearect(length,breadth));
	printf("\nEnter radius ");
	scanf("%d",&radius);
	printf("Area of Circle = %f",areacircle(radius));
}
