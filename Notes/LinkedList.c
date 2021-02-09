//Linked List Operations
#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *start = NULL, *end = NULL;
main()
{
	int ch;
	while (1)
	{
		printf("\n 1.Create");
		printf("\n 2.Display");
		printf("\n 3.Insert Begin");
		printf("\n 4.Insert Middle");
		printf("\n 5.Delete Begin");
		printf("\n 6.Delete Middle");
		printf("\n 7.Delete End");
		printf("\n 8.Count");
		printf("\n 9.Exit");
		printf("\n Enter your choice ");
		scanf("%d",&ch);
		switch (ch)
		{
			case 1: create();break;
			case 2: display();break;
			case 3: insertbegin();break;
			case 4: insertmiddle();break;
			case 5: deletebegin();break;
			case 6: deletemiddle();break;
			case 7: deleteend();break;
			case 8: count();break;
			case 9: exit(1);
		}
		
	}
}
create()
{
	struct node *p;
	p = (struct node*)malloc(sizeof(struct node));
	printf("\n Enter data ");
	scanf("%d",&p->data);
	p->link = NULL;
	if (start == NULL)
		start=end=p;
	else
	{
		end->link = p;
		end = p;
	}
}
display()
{
	struct node *p;
	p = start;
	printf("\n The elements are \n");
	while (p != NULL)
	{
		printf("%d ",p->data);
		p = p->link;
	}
}
insertbegin()
{
	struct node *p;
	p = (struct node *)malloc(sizeof(struct node));
	printf("\n Enter Data ");
	scanf("%d",&p->data);
	p->link = start;
	start = p;
}
insertmiddle()
{
	struct node *p,*new;
	int pos,i;
	p = start;
	new = (struct node *)malloc(sizeof(struct node));
	printf("\n Enter Data ");
	scanf("%d",&new->data);
	printf("\n Enter position to insert ");
	scanf("%d",&pos);
	for(i=1;i<pos;i++)
		p = p->link;
	new->link = p->link;
	p->link = new;
}
deletebegin()
{
	struct node *p;
	p = start;
	start = start->link;
	free(p);
}
deletemiddle()
{
	int n,i=2;
	struct node *p,*q,*temp;
	p = start;
	printf("Delete which node ");
	scanf("%d",&n);
	while (i < n)
	{
		p = p->link;
		i++;
	}
	q = p->link->link;
	temp = p->link;
	p->link = q;
	free(temp);
}
deleteend()
{
	struct node *p;
	p = start;
	while (p->link->link != NULL)
		p = p->link;
	p->link = NULL;
	free(end);
	end = p;
}
count()
{
	struct node *p;
	int c = 0;
	p = start;
	while (p!= NULL)
	{
		c++;
		p = p->link;
	}
	printf("Number of Nodes = %d",c);
}










