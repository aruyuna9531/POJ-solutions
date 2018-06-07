/*
Description

Businesses like to have memorable telephone numbers. One way to make a telephone number memorable is to have it spell a memorable word or phrase. For example, you can call the University of Waterloo by dialing the memorable TUT-GLOP. Sometimes only part of the number is used to spell a word. When you get back to your hotel tonight you can order a pizza from Gino's by dialing 310-GINO. Another way to make a telephone number memorable is to group the digits in a memorable way. You could order your pizza from Pizza Hut by calling their ``three tens'' number 3-10-10-10. 

The standard form of a telephone number is seven decimal digits with a hyphen between the third and fourth digits (e.g. 888-1200). The keypad of a phone supplies the mapping of letters to numbers, as follows: 

A, B, and C map to 2 
D, E, and F map to 3 
G, H, and I map to 4 
J, K, and L map to 5 
M, N, and O map to 6 
P, R, and S map to 7 
T, U, and V map to 8 
W, X, and Y map to 9 

There is no mapping for Q or Z. Hyphens are not dialed, and can be added and removed as necessary. The standard form of TUT-GLOP is 888-4567, the standard form of 310-GINO is 310-4466, and the standard form of 3-10-10-10 is 310-1010. 

Two telephone numbers are equivalent if they have the same standard form. (They dial the same number.) 

Your company is compiling a directory of telephone numbers from local businesses. As part of the quality control process you want to check that no two (or more) businesses in the directory have the same telephone number. 
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int phoneList[100001];
int AlToNum(char x){
	switch(x)
	{
	case 'A':
	case 'B':
	case 'C':
		return 2;
	case 'D':
	case 'E':
	case 'F':
		return 3;
	case 'G':
	case 'H':
	case 'I':
		return 4;
	case 'J':
	case 'K':
	case 'L':
		return 5;
	case 'M':
	case 'N':
	case 'O':
		return 6;
	case 'P':
	case 'R':
	case 'S':
		return 7;
	case 'T':
	case 'U':
	case 'V':
		return 8;
	case 'W':
	case 'X':
	case 'Y':
		return 9;
	default: return -1;
	}
}

int convert(char *str){
	int counter=0,i=0,val=0;
	while(counter<7)
	{
		if(str[i]>='0' && str[i]<='9'){
			val*=10;
			val+=(int)str[i]-48;
			counter++;
		}
		else if(str[i]>='A' && str[i]<='Z'){
			val*=10;
			val+=AlToNum(str[i]);
			counter++;
		}
		i++;
	}
	return val;
}

int comp(const void *a,const void *b)
{
return *(int*)a-*(int*)b;
}
void quickSort(int *arr, int Len){
    qsort(arr, Len, sizeof(int), comp);
}


int main()
{
	int c,i,tmp,ct=0,exist=0;
	char ac[500];
	scanf("%d",&c);
	for(i=0;i<c;i++){
		scanf("%s",ac);
		phoneList[i]=convert(ac);
	}
	//phoneList[c]=10000000;
	quickSort(phoneList, c);
	for(i=0;i<c;i++){
		if(ct==0){
			tmp=phoneList[i];
			ct=1;
		}
		else
		{
			if(tmp==phoneList[i]){
				ct++;
				exist=1;
			}
			else
			{
				if(ct>1)printf("%03d-%04d %d\n",tmp/10000,tmp%10000,ct);
				ct=0;
				i--;
			}
		}
	}
	if(ct>1)printf("%03d-%04d %d\n",tmp/10000,tmp%10000,ct);
	if(exist==0)printf("No duplicates.\n");
	return 0;
}
