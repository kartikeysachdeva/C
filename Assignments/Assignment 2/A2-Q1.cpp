/* WAP to check whether the given age is major(>=18) or minor.
	Note: if the given age is <0 then display "Invalid Age"
	*/
#include<stdio.h>
main()
{
	int age; 
	printf("Enter age: ");
	scanf("%d", &age);
	if (age>=18){
		printf("Major");
	}
	else{
		if(age<18&&age>=0){
			printf("Minor");
		}
		else{
			if(age<0){
				printf("Invalid age");
			}
		}
	}

	
}
