/*
Description

A calendar is a system for measuring time, from hours and minutes, to months and days, and finally to years and centuries. The terms of hour, day, month, year and century are all units of time measurements of a calender system. 
According to the Gregorian calendar, which is the civil calendar in use today, years evenly divisible by 4 are leap years, with the exception of centurial years that are not evenly divisible by 400. Therefore, the years 1700, 1800, 1900 and 2100 are not leap years, but 1600, 2000, and 2400 are leap years. 
Given the number of days that have elapsed since January 1, 2000 A.D, your mission is to find the date and the day of the week.
Input

The input consists of lines each containing a positive integer, which is the number of days that have elapsed since January 1, 2000 A.D. The last line contains an integer −1, which should not be processed. 
You may assume that the resulting date won’t be after the year 9999.

Output

For each test case, output one line containing the date and the day of the week in the format of "YYYY-MM-DD DayOfWeek", where "DayOfWeek" must be one of "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" and "Saturday".

Sample Input

1730
1740
1750
1751
-1

Sample Output

2004-09-26 Sunday
2004-10-06 Wednesday
2004-10-16 Saturday
2004-10-17 Sunday
*/

/*
从2000年1月1日开始数x天，给出日期和星期
*/

#include<cstdio>
#define days_400year 146097
#define days_100year 36524
#define days_4year 1461

void daycount(int x,int leap)
{
	int month,day;
	if(x<31)
	{
		month=1;
		day=x+1;
	}
	else if(x<59+leap)
	{
		month=2;
		day=x-30;
	}
	else if(x<90+leap)
	{
		month=3;
		day=x-58-leap;
	}
	else if(x<120+leap)
	{
		month=4;
		day=x-89-leap;
	}
	else if(x<151+leap)
	{
		month=5;
		day=x-119-leap;
	}
	else if(x<181+leap)
	{
		month=6;
		day=x-150-leap;
	}
	else if(x<212+leap)
	{
		month=7;
		day=x-180-leap;
	}
	else if(x<243+leap)
	{
		month=8;
		day=x-211-leap;
	}
	else if(x<273+leap)
	{
		month=9;
		day=x-242-leap;
	}
	else if(x<304+leap)
	{
		month=10;
		day=x-272-leap;
	}
	else if(x<334+leap)
	{
		month=11;
		day=x-303-leap;
	}
	else
	{
		month=12;
		day=x-333-leap;
	}
	printf("-");
	if(month<=9)printf("0%d",month);else printf("%d",month);
	printf("-");
	if(day<=9)printf("0%d ",day);else printf("%d ",day);
}

void dowprint(int dow)
{
	switch(dow)
	{
	case 0:printf("Sunday\n");break;
	case 1:printf("Monday\n");break;
	case 2:printf("Tuesday\n");break;
	case 3:printf("Wednesday\n");break;
	case 4:printf("Thursday\n");break;
	case 5:printf("Friday\n");break;
	case 6:printf("Saturday\n");break;
	}
}

int main()
{
	int year,month,day,dow;
	int i=0;
	for(;;)
	{
		year=2000;
		month=1;
		day=1;
		dow=6;
		scanf("%d",&i);
		if(i==-1)break;
	//2000-1-1 Saturday
		dow=(i+6)%7;
	//century
		year+=i/days_400year*400;
		int c=i%days_400year;
		if(c<=36524)
		{
			year+=c/days_4year*4;
			c=c%days_4year;
			//1年leap
			if(c<=365)
			{
				printf("%d",year);
				daycount(c,1);
				dowprint(dow);
			}
			else
			{
				c-=366;
				year+=1;
				year+=c/365;
				c%=365;
				printf("%d",year);
				daycount(c,0);
				dowprint(dow);
			}
		}
		else
		{
			year+=100;
			c-=36525;
			year+=c/days_100year*100;
			c%=days_100year;
			if(c<=365*4-1)
			{
				if(c<=364)
				{
					printf("%d",year);
					daycount(c,0);
					dowprint(dow);
				}
				else
				{
					year+=c/365;
					c%=365;
					printf("%d",year);
					daycount(c,0);
					dowprint(dow);
				}
			}
			else
			{
				c-=365*4;
				year+=4;
				year+=c/days_4year*4;
				c%=days_4year;
				if(c<=365)
				{
					printf("%d",year);
					daycount(c,1);
					dowprint(dow);
				}
				else
				{
					c-=366;
					year+=1;
					year+=c/365;
					c%=365;
					printf("%d",year);
					daycount(c,0);
					dowprint(dow);
				}
			}
		}
	}
	return 0;
}
