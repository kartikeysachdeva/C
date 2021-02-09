//WAP to find biggest of given three numbers using conditional operator (?)
#include<stdio.h>
main(){
	int x,y,z,biggest;
	printf("Enter 3 numbers: ");
	scanf("%d%d%d", &x,&y,&z);
	biggest= (x>y)?(x>z? x:z): (y>z? y:z);
	printf("Biggest number is : %d", biggest);
}
