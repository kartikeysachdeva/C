/*WAP to accept item number, item name, rate and quantity. Find price (rate * qty).
	Calculate discount as follows

	if (price >= 1000 and < 2000)
	    dis is 10% on price
	if (price >= 2000 and < 3000)
	    dis is 15% on price
	if (price >= 3000 and < 5000)
	    dis is 20% on price
	if (price >= 5000)
	    dis is 25% on price

	Find netprice (price - dis)
	Display item number, item name, price, discount and net price
	
	Program
	-------
	if (price >= 1000 && price < 2000)
	    dis = 0.10 * price;
	    */

#include <stdio.h>
main()
{
	int itemNum;
	char itemName[200];
	float rate, quantity, price, discount, netPrice;
	printf("Enter Item number, Item name, Rate, Quantity: ");
	scanf("%d%s%f%f", &itemNum,itemName,&rate,&quantity,&price);
	
	price=rate*quantity;
	if (price >= 1000 && price < 2000){
		discount= 0.1*price;
	}
	else{
		if (price >= 2000 && price < 3000){
			discount= 0.15*price;
		}
		else{
			if (price >= 3000 && price < 5000){
				discount= 0.2*price;
			}
			else {
				if (price >= 5000){
					discount= 0.25*price;
				}
			}
		}
	}
	netPrice= price-discount;
	printf("Item Number: %d \nItem Name:%s \nPrice:%.2f \nDiscount:%.2f \nNet Price:%.2f \n", itemNum, itemName, price, discount, netPrice);
	return 0;
	
	
	 
}
