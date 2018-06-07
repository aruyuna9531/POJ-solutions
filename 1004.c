/*
Description

Larry graduated this year and finally has a job. He's making a lot of money, but somehow never seems to have enough. Larry has decided that he needs to grab hold of his financial portfolio and solve his financing problems. The first step is to figure out what's been going on with his money. Larry has his bank account statements and wants to see how much money he has. Help Larry by writing a program to take his closing balance from each of the past twelve months and calculate his average account balance.
*/

#include<stdio.h>
int main()
{
	int i;
	double a=0.00,tot=0.00;
	for(i=0;i<12;i++){
		scanf("%lf",&a);
		tot+=a;
	}
	printf("$%.2f\n",tot/12.0);
	return 0;
}
