#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct student 
{
	char name[20];
	int grade;
	int age; 
	float mark;
	double height; 
	int rollno;
}STD;

int getInput(STD* stud)
{
		printf("\nWhat is the name of student?");
		fflush(stdin);
		gets(stud->name);
		printf("\nWhat class is student in?")
		scanf("%d", &stud->grade)
		printf("\nHow old is the student?")
		scanf("%d", &stud->age)
		printf("\nWhat is the students mark?")
		scanf("%f", &stud->mark)
		printf("\nWhat is the students height")
		scanf("%lf", &stud->height)
		printf("\nWhat is the students rollno")
		scanf("%d", &stud->rollno)	
}


int output(STD stud[], int count)
{
	int i;
	for(i=0;i<count;i++)
	{
		printf ("Name: %s", stud[i].name);
		printf ("Cass : %d", stud.grade);
		printf ("Age  : %ld", stud.age);
		printf ("Mark : %c", stud.mark);
		printf ("Height  : %d", stud.height);
		printf ("Roll#: %f", stud.rollno);
	}
}


main()
{
	STD stud[10];
	FILE *ffile;
	char firstfile[80];
	int i,j,num,var, count=1;
	char input;
	
	printf("What do you want to name the file?");
	gets(firstfile);
	ffile= fopen(firstfile, "wt");
	do
	{
		getInput(&stud[count]);
		printf("Do you want another input?");
		fflush(stdin);
		scanf("%c", &input);
		count++;
			
	} while(toupper(input)=='Y');
	
	for(i=0;i<count;i++)
	{
		fprintf(ffile, "%s\n", stud[i].name);	
	}		
}
