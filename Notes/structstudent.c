#include <stdio.h>
struct student
{
	int rollno;
	char name[10];
	float mark1,mark2,mark3,total,avg;
};
main()
{
	
	struct student stud;
	printf("Enter roll no ");
	scanf("%d",&stud.rollno);
	printf("Enter Name ");
	scanf("%s",stud.name);
	printf("Enter three marks ");
	scanf("%f%f%f",&stud.mark1,&stud.mark2,&stud.mark3);
	stud.total = stud.mark1 + stud.mark2 + stud.mark3;
	stud.avg = stud.total / 3;
	dispStudent(stud);
}
dispStudent(struct student stud)
{
	printf("Roll No = %d\n",stud.rollno);
	printf("Name = %s\n",stud.name);
	printf("Total Marks = %f\n",stud.total);
	printf("Average = %f\n",stud.avg);
}
