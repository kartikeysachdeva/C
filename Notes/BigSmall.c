#include <stdio.h>
main()
{
	int n[5],i,big,sbig,small,ssmall;
	printf("Enter 5 values\n");
	for(i=0;i<5;i++)
		scanf("%d",&n[i]);
	//{5,8,6,4,7}
	big = n[0];
	for(i=1;i<5;i++)
	{
		if (n[i] > big)
			big = n[i];
	}
	//big=8
	sbig = n[0];
	for(i=1;i<5;i++)
	{
		if (n[i] > sbig && n[i] < big)
			sbig = n[i];
	}
	small = n[0];
	for(i=1;i<5;i++)
	{
		if(n[i] < small)
			small = n[i];
	}
	ssmall = n[0];
	for(i=1;i<5;i++)
	{
		if (n[i] < ssmall && n[i] > small)
			ssmall = n[i];
	}
	printf("Big = %d\n",big);
	printf("Second Big = %d\n",sbig);
	printf("Small = %d\n",small);
	printf("Second Small = %d\n",ssmall);
}
