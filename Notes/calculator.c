#include <stdio.h>
main()
{
	int n1,n2,res,ch;
	printf("Enter two numbers ");
	scanf("%d%d",&n1,&n2);
	printf("\n 1.Add");
	printf("\n 2.Subtract");
	printf("\n 3.Multiply");
	printf("\n 4.Divide");
	printf("\n Enter your choice ");
	scanf("%d",&ch);
	switch (ch)
	{
		case 1: res = n1 + n2;break;
		case 2: res = n1 - n2;break;
		case 3: res = n1 * n2;break;
		case 4: res = n1 / n2;break;
		default: printf("\n Invalid Choice");exit(1);//comes out of program
	}
	printf("\n Result = %d",res);
}
