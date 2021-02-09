//static variable
main()
{
	int i;
	for(i=1;i<=3;i++)
		myfun();
}
myfun()
{
	static int x=0;
	x++;
	printf("x = %d\n",x);
}
/*
output
------
x = 1
x = 2
x = 3
*/
