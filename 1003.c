/*
Description

How far can you make a stack of cards overhang a table? If you have one card, you can create a maximum overhang of half a card length. (We're assuming that the cards must be perpendicular to the table.) With two cards you can make the top card overhang the bottom one by half a card length, and the bottom one overhang the table by a third of a card length, for a total maximum overhang of 1/2 + 1/3 = 5/6 card lengths. In general you can make n cards overhang by 1/2 + 1/3 + 1/4 + ... + 1/(n + 1) card lengths, where the top card overhangs the second by 1/2, the second overhangs tha third by 1/3, the third overhangs the fourth by 1/4, etc., and the bottom card overhangs the table by 1/(n + 1). This is illustrated in the figure below.
*/

#include<stdio.h>

int main()
{
	int a=1;
	double c;
	scanf("%lf",&c);
	while(c>0.000001)
	{
		a=1;
		while(c>0.0)
		{
			c-=1.0/(double)(a+1.0);
			a++;
		}
		printf("%d card(s)\n",a-1);
		scanf("%lf",&c);
	}
	return 0;
}
