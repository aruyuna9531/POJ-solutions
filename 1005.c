/*
Fred Mapper is considering purchasing some land in Louisiana to build his house on. In the process of investigating the land, he learned that the state of Louisiana is actually shrinking by 50 square miles each year, due to erosion caused by the Mississippi River. Since Fred is hoping to live in this house the rest of his life, he needs to know if his land is going to be lost to erosion. 

After doing more research, Fred has learned that the land that is being lost forms a semicircle. This semicircle is part of a circle centered at (0,0), with the line that bisects the circle being the X axis. Locations below the X axis are in the water. The semicircle has an area of 0 at the beginning of year 1. (Semicircle illustrated in the Figure.) 
*/

#include<stdio.h>
int main()
{
	double pi=3.14159265358979;
	int year = 0,n,i;
	double x,y;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%lf%lf",&x,&y);
		year = (int)(pi*(x*x+y*y)/100.0)+1;
		printf("Property %d: This property will begin eroding in year %d.\n",i+1,year);
	}
	printf("END OF OUTPUT.\n");
	return 0;
}
