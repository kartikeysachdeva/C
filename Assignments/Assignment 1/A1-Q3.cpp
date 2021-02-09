//WAP to accect item number, item name, rate and quantity. Find price (rate * qty).
//  Display item number, item name and price

#include <stdio.h>
main()
{
	int itemNum;
	char itemName[200];
	float r, q, p;
	printf("Enter Item number, Item name, Rate, Quantity: ");
	scanf("%d%s%f%f", &itemNum,itemName,&r,&q,&p);
	
	p=r*q;
	
	printf("Item Number: %d \nItem Name:%s \nPrice:%.2f \n", itemNum, itemName, p);
	
	return 0;
	
	
	 
}
