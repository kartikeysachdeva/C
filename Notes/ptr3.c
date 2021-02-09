//Pointers and Functions 
//Swap two numbers - call-by-value
main()
{
	int n1,n2;
	printf("Enter two numbers ");
	scanf("%d%d",&n1,&n2);
	printf("Before Swap n1=%d n2=%d\n",n1,n2);
	swap(n1,n2);
	printf("After Swap n1=%d n2=%d\n",n1,n2);
}
swap(int n1,int n2)
{
	int t;
	t = n1;
	n1 = n2;
	n2 = t;
}
/*
output
------
Enter two numbers 10 20
Before Swap n1=10 n2=20
After Swap n1=10 n2=20
*/
