//WAP to find sum of prime numbers from 2 to 100
#include<stdio.h>
main()
{
	int i,j,x,sum=0;
	for(i=2;i<100;i++){
		x=1;
		for(j=2;j<i;j++){
		if(i%j==0){
			x=0;
			break;
		}	
		}
		if(x==1){
			printf("%d\n",i);
			sum+=i;
		}
	}
	printf("%d", sum);
}
