#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

int multiply(int input, int power)
{
	int ans;
	if(power==1)
	{
		return 1;
	}
	else
	{
		ans = input * pow(input, power-1);
	}
	
	return ans;
}

int output(int ans)
{
	printf("The answer is %d", ans);
}

main()
{
	int x,y, ans;
	printf("Enter a num and its power");
	scanf("%d%d", &x, &y);
	
	ans= multiply(x,y);
	output(ans);
}

