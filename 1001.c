/*
Description

Problems involving the computation of exact values of very large magnitude and precision are common. For example, the computation of the national debt is a taxing experience for many computer systems. 

This problem requires that you write a program to compute the exact value of Rn where R is a real number ( 0.0 < R < 99.999 ) and n is an integer such that 0 < n <= 25.
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX 126
//进位处理，超过10的结果往前进位
void slide(int *res, int Length)
{
	int i=0;
	for(i=0;i<Length;i++){
		if(res[i]>=10){
			res[i+1]+=res[i]/10;
			res[i]%=10;
		}
	}
}
void Singlemul(int *res, const int *a, const int b, int aLength)
{
	int i=0;
	for(i=0;i<aLength;i++)res[i]=a[i]*b;
	slide(res,aLength);
}
void add(int *res, int *adder, int pls, int adderLength)
{
	int i=0;
	for(i=0;i<adderLength;i++){
		res[pls+i]+=adder[i];
		slide(res,pls+adderLength);	//可以再剪枝
	}
}

void Totalmul(int *res, const int *a, const int *b, int aLength, int bLength, int resLength)
{
	int i,j,*tmp;
	tmp=(int*)malloc(resLength*sizeof(int));
	for(j=0;j<resLength;j++)res[j]=0;
	for(i=0;i<resLength;i++)tmp[i]=0;
#ifdef debug
		printf("current data: a=");
		for(i=aLength-1;i>=0;i--){
			printf("%d",a[i]);
		}
		printf(",b=");
		for(i=bLength-1;i>=0;i--){
			printf("%d",b[i]);
		}
		printf(".\n");
#endif
	for(i=0;i<bLength;i++){
		Singlemul(tmp,a,b[i],aLength);
#ifdef debug
		printf("i=%d, \ntmp=",i);
		for(j=resLength-1;j>=0;j--){
			printf("%d",tmp[j]);
		}
		printf("\n");
#endif
		add(res, tmp, i, aLength+1);
#ifdef debug
		printf("res=");
		for(j=resLength-1;j>=0;j--){
			printf("%d",res[j]);
		}
		printf("\n");
#endif
		for(j=0;j<resLength;j++)tmp[j]=0;
	}
	free(tmp);
}

void printres(int *res, int pointpos)
{
	int i=0,FrontTrace=MAX-1, BackTrace=0,IsInteger=1,IsBiggerThanOne=0, IsZero=1;
	for(i=0;i<MAX&&i<=pointpos;i++){
		BackTrace=i;
		if(res[i]!=0){
			IsInteger=0;
			IsZero=0;
			break;
		}
	}
	for(i=MAX-1; i>=0 && i>=pointpos-1;i--)
	{
		FrontTrace=i;
		if(res[i]!=0){
			IsBiggerThanOne=1;
			IsZero=0;
			break;
		}
	}
	if(IsZero==1)printf("0");
	else for(i=FrontTrace; i>=BackTrace; i--){
		if(i==pointpos-1)printf(".");
		printf("%d",res[i]);
	}
}

int main()
{
	char s[7]={'\0'};
	int times;
	while(scanf("%s%d",s,&times)!=EOF){
		int i=0,j=0,res[MAX]={0},muler[5]={0,0,0,0,0};
		int pointpos=0,mulerEqualsZero=1,timescounter=1;
		int res_tmp[125]={0};

		if(s[0]=='.'){
			pointpos=5;
			muler[4]=(int)s[1]-48;
			muler[3]=(int)s[2]-48;
			muler[2]=(int)s[3]-48;
			muler[1]=(int)s[4]-48;
			muler[0]=(int)s[5]-48;
		}
		else
		{
			muler[4]=(int)s[0]-48;
			if(s[1]=='.'){
				pointpos=4;
				muler[3]=(int)s[2]-48;
				muler[2]=(int)s[3]-48;
				muler[1]=(int)s[4]-48;
				muler[0]=(int)s[5]-48;
			}
			else{
				muler[3]=(int)s[1]-48;
				if(s[2]=='.'){
					pointpos=3;
					muler[2]=(int)s[3]-48;
					muler[1]=(int)s[4]-48;
					muler[0]=(int)s[5]-48;
				}
				else
				{
					muler[2]=(int)s[2]-48;
					if(s[3]=='.'){
						pointpos=2;
						muler[1]=(int)s[4]-48;
						muler[0]=(int)s[5]-48;
					}
					else
					{
						muler[1]=(int)s[3]-48;
						if(s[4]=='.'){
							pointpos=1;
							muler[0]=(int)s[5]-48;
						}
						else
						{
							pointpos=0;
							muler[0]=(int)s[4]-48;
						}
					}
				}
			}
		}

		for(i=0;i<5;i++){
			if(muler[i]!=0)mulerEqualsZero=0;
		}
		if(mulerEqualsZero==1){
			printf("0\n");
			continue;
		}
		if(times==0){
			printf("1\n");
			continue;
		}
		if(times==1){
			for(i=0;i<5;i++)res[i]=muler[i];
			printres(res, pointpos);
			printf("\n");
			continue;
		}
		pointpos*=times;
		for(i=0;i<5;i++)res_tmp[i]=muler[i];
		for(i=0;i<times-1;i++){
			Totalmul(res, res_tmp, muler, 5*timescounter, 5, 5*(timescounter+1));
			timescounter++;
			for(j=0;j<5*(timescounter+1);j++)res_tmp[j]=res[j];
		}
		printres(res, pointpos);
		printf("\n");
	}
	return 0;
}
