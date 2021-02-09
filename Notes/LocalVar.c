//Local Variables
main()
{
	int n=10;//local variable
	printf("n = %d\n",n);
	fun(n);
	printf("n = %d\n",n);
}
fun(int n)//local variable
{
	n = n + 10;
	printf("n = %d\n",n);
}
/*
output
------
n = 10
n = 20
n = 10
*/
