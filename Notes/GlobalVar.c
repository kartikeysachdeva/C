//Global Variables
int n=10;//global variable
main()
{
	printf("n = %d\n",n);
	fun1();
	printf("n = %d\n",n);
	fun2();
	printf("n = %d\n",n);
}
fun1()
{
	n = n + 10;
	printf("n = %d\n",n);
}
fun2()
{
	int n=30;//local variable
	printf("n = %d\n",n);
}
/*
output
------
n = 10
n = 20
n = 20
n = 30
n = 20
*/
