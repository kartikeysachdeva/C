/*
to find total marks and average
of given three subject marks
*/
#include <stdio.h>
main()
{
	int rollno;
	float mark1,mark2,mark3,total,avg;
	char name[10];//string - collection of characters
	printf("Enter roll no ");
	scanf("%d",&rollno);
	printf("Enter Name ");
	scanf("%s",name);
	printf("Enter three marks ");
	scanf("%f%f%f",&mark1,&mark2,&mark3);
	total = mark1 + mark2 + mark3;
	avg = total/3;
	printf("Roll No = %d\n",rollno);
	printf("Name = %s\n",name);
	printf("Total Marks = %.2f\n",total);
	printf("Average = %.2f\n",avg);
}
