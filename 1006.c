/*
Description

Some people believe that there are three cycles in a person's life that start the day he or she is born. These three cycles are the physical, emotional, and intellectual cycles, and they have periods of lengths 23, 28, and 33 days, respectively. There is one peak in each period of a cycle. At the peak of a cycle, a person performs at his or her best in the corresponding field (physical, emotional or mental). For example, if it is the mental curve, thought processes will be sharper and concentration will be easier. 
Since the three cycles have different periods, the peaks of the three cycles generally occur at different times. We would like to determine when a triple peak occurs (the peaks of all three cycles occur in the same day) for any person. For each cycle, you will be given the number of days from the beginning of the current year at which one of its peaks (not necessarily the first) occurs. You will also be given a date expressed as the number of days from the beginning of the current year. You task is to determine the number of days from the given date to the next triple peak. The given date is not counted. For example, if the given date is 10 and the next triple peak occurs on day 12, the answer is 2, not 3. If a triple peak occurs on the given date, you should give the number of days to the next occurrence of a triple peak. 
*/

#include<stdio.h>

int main(){
	int p,e,i,d,counter,n=1,p1,e1,i1,elapse;
	while(scanf("%d%d%d%d",&p,&e,&i,&d)!=EOF){
		if(p==-1)break;
		p1=p%23;
		e1=e%28;
		i1=i%33;
		for(counter=i+33;counter<=21252+i;counter+=33)
		{
			if((counter-p1)%23==0 && (counter-e1)%28==0)break;
		}
		elapse = counter-d;
		if(elapse>21252)elapse-=21252;
		printf("Case %d: the next triple peak occurs in %d days.\n",n++,elapse);		
	}
	return 0;
}
