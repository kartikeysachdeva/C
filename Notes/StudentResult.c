#include <stdio.h>
main()
{
	int rollno, mark1,mark2,mark3,total,avg;
	char name[10],result[6],division[15];
	printf("Enter Roll No ");
	scanf("%d",&rollno);
	printf("Enter Name ");
	scanf("%s",name);
	printf("Enter three marks ");
	scanf("%d%d%d",&mark1,&mark2,&mark3);
	total = mark1 + mark2 + mark3;
	avg = total/3;
	if (mark1 >= 40 && mark2 >= 40 && mark3 >= 40)
		strcpy(result,"pass");
	else
		strcpy(result,"fail");
	if ((strcmp(result,"pass")) == 0)
	{
		if (avg >= 70)
			strcpy(division,"Distinction");
		else
			if (avg >= 60 && avg < 70)
				strcpy(division,"First");
			else
				if (avg >= 50 && avg < 60)
					strcpy(division,"Second");
				else
					if (avg >= 40 && avg < 50)
						strcpy(division,"Third");
	}
	else
		strcpy(division,"Nil");
	printf("Roll No = %d\n",rollno);
	printf("Name = %s\n",name);
	printf("Total Marks = %d\n",total);
	printf("Average = %d\n",avg);
	printf("Result = %s\n",result);
	printf("Division = %s\n",division);
}
