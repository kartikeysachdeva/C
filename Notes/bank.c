#include <stdio.h>
main()
{
	int bal,amt,ch;
	printf("Enter current balance ");
	scanf("%d",&bal);
	do
	{
		printf("\n 1.Deposit");
		printf("\n 2.Withdraw");
		printf("\n 3.Display Balance");
		printf("\n 4.Exit");
		printf("\n Enter your choice ");
		scanf("%d",&ch);
		switch (ch)
		{
			case 1: printf("\n Enter amount to deposit ");
			 		scanf("%d",&amt);
			 		bal = bal + amt;break;
			case 2: printf("\n Enter amount to withdraw ");
					scanf("%d",&amt);
					if (amt > bal)
						printf("\n Insuffient balance");
					else
						bal = bal - amt;
					break;
			case 3: printf("\n Current Balance = %d",bal);break;
			case 4: printf("\n Thank you for banking");break;
			default: printf("\n Invalid Choice");
		}
	}while (ch != 4);
	
}
