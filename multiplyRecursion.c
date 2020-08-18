#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

int multiplication(int num1, int num2)
{
	int ans=0;
	if(num1<num2)
	{
		return multiplication(num2,num1);
	}
	else if(num2!=0)
	{
		return(num1+multiplication(num1,num2-1));
	}
	else
	{
		return 0;
	}
	
}

int output(int x, int y, int ans)
{
	printf("%d * %d = %d", x,y,ans);
}

main()
{
	int x,y, ans;
	printf("Enter 2 nums");
	scanf("%d%d", &x, &y);
	
	ans= multiplication(x,y);
	output(x,y,ans);
}

