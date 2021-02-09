//Pointers and Structures
struct employee
{
	int eno;
	char ename[10];
	float salary;	
};
main()
{
	struct employee e;
	printf("Enter Emp No, Emp Name and Salary ");
	scanf("%d%s%f",&e.eno,e.ename,&e.salary);
	dispEmp(&e);
}
dispEmp(struct employee *p)
{
	printf("Emp No : %d\n",p->eno);
	printf("Emp Name : %s\n",p->ename);
	printf("Emp Salary : %f\n",p->salary);
}

