#include <stdio.h>
int reverse (int num);
int palindrome(int pal, int num);
int main()
{
	int pal,num; 
	printf("Enter a number ");
	scanf("%d", &num);
	pal = reverse(num);
	palindrome(pal, num);
}

int reverse (int num)
{
	int rev; 
	while (num != 0)
	{
		rev = rev * 10 + num % 10;
		num = num / 10;
	}
	printf("Reverse = %d\n",rev);
	return rev;
	
}
int palindrome(int pal, int num)
{
	if (pal == num)
	{
		printf("This number is a palindrome");
	}
}
