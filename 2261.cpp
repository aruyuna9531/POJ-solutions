/*
Description

Today the first round of the Soccer World Championship in France is coming to an end. 16 countries are remaining now, among which the winner is determined by the following tournament: 

 1 Brazil -----+	

   	       +-- ? --+

 2 Chile ------+       |

		       +-- ? --+

 3 Nigeria ----+       |       |

	       +-- ? --+       |

 4 Denmark ----+	       |

	                       +-- ? --+

 5 Holland ----+	       |       |

	       +-- ? --+       |       |

 6 Yugoslavia -+       |       |       |

		       +-- ? --+       |

 7 Argentina --+       |	       |

	       +-- ? --+	       |

 8 England ----+		       |

				       +-- World Champion

 9 Italy ------+		       |

	       +-- ? --+	       |

10 Norway -----+       |               |

		       +-- ? --+       |

11 France -----+       |       |       |

	       +-- ? --+       |       |

12 Paraguay ---+	       |       |

			       +-- ? --+

13 Germany ----+	       |

	       +-- ? --+       |

14 Mexico -----+       |       |

		       +-- ? --+

15 Romania ----+       |

	       +-- ? --+

16 Croatia ----+

For each possible match A vs. B between these 16 nations, you are given the probability that team A wins against B. This (together with the tournament mode displayed above) is sufficient to compute the probability that a given nation wins the World Cup. For example, if Germany wins against Mexico with 80%, Romania against Croatia with 60%, Germany against Romania with 70% and Germany against Croatia with 90%, then the probability that Germany reaches the semi-finals is 80% * (70% * 60% + 90% * 40%) = 62.4%. 
Your task is to write a program that computes the chances of the 16 nations to become the World Champion '98.
*/
/*给出16支队伍名字和与各对手踢一场获胜概率矩阵，求每支队伍获得总冠军的概率*/

#include<cstdio>

char nation[16][11];
double probable[16][16];
double dp[3][16];

int main()
{
	int i,j;
	for(i=0;i<16;i++)
	{
		for(j=0;nation[i][j-1]!=10;j++)scanf("%c",&nation[i][j]);
		nation[i][10]='\0';
		for(j=9;nation[i][j]<33;j--)nation[i][j]=32;
	}
	for(i=0;i<16;i++)for(j=0;j<16;j++){scanf("%lf",&probable[i][j]);probable[i][j]/=100;}
	//1/8finals
	for(i=0;i<16;i+=2)dp[0][i]=probable[i][i+1];
	for(i=1;i<16;i+=2)dp[0][i]=probable[i][i-1];
	//1/4finals
	dp[1][0]=dp[0][0]*(probable[0][2]*dp[0][2]+probable[0][3]*dp[0][3]);
	dp[1][1]=dp[0][1]*(probable[1][2]*dp[0][2]+probable[1][3]*dp[0][3]);
	dp[1][2]=dp[0][2]*(probable[2][0]*dp[0][0]+probable[2][1]*dp[0][1]);
	dp[1][3]=dp[0][3]*(probable[3][0]*dp[0][0]+probable[3][1]*dp[0][1]);
	dp[1][4]=dp[0][4]*(probable[4][6]*dp[0][6]+probable[4][7]*dp[0][7]);
	dp[1][5]=dp[0][5]*(probable[5][6]*dp[0][6]+probable[5][7]*dp[0][7]);
	dp[1][6]=dp[0][6]*(probable[6][4]*dp[0][4]+probable[6][5]*dp[0][5]);
	dp[1][7]=dp[0][7]*(probable[7][4]*dp[0][4]+probable[7][5]*dp[0][5]);
	dp[1][8]=dp[0][8]*(probable[8][10]*dp[0][10]+probable[8][11]*dp[0][11]);
	dp[1][9]=dp[0][9]*(probable[9][10]*dp[0][10]+probable[9][11]*dp[0][11]);
	dp[1][10]=dp[0][10]*(probable[10][8]*dp[0][8]+probable[10][9]*dp[0][9]);
	dp[1][11]=dp[0][11]*(probable[11][8]*dp[0][8]+probable[11][9]*dp[0][9]);
	dp[1][12]=dp[0][12]*(probable[12][14]*dp[0][14]+probable[12][15]*dp[0][15]);
	dp[1][13]=dp[0][13]*(probable[13][14]*dp[0][14]+probable[13][15]*dp[0][15]);
	dp[1][14]=dp[0][14]*(probable[14][12]*dp[0][12]+probable[14][13]*dp[0][13]);
	dp[1][15]=dp[0][15]*(probable[15][12]*dp[0][12]+probable[15][13]*dp[0][13]);
	//Semifinal
	for(i=0;i<4;i++)dp[2][i]=dp[1][i]*(probable[i][4]*dp[1][4]+probable[i][5]*dp[1][5]+probable[i][6]*dp[1][6]+probable[i][7]*dp[1][7]);
	for(i=4;i<8;i++)dp[2][i]=dp[1][i]*(probable[i][0]*dp[1][0]+probable[i][1]*dp[1][1]+probable[i][2]*dp[1][2]+probable[i][3]*dp[1][3]);
	for(i=8;i<12;i++)dp[2][i]=dp[1][i]*(probable[i][12]*dp[1][12]+probable[i][13]*dp[1][13]+probable[i][14]*dp[1][14]+probable[i][15]*dp[1][15]);
	for(i=12;i<16;i++)dp[2][i]=dp[1][i]*(probable[i][8]*dp[1][8]+probable[i][9]*dp[1][9]+probable[i][10]*dp[1][10]+probable[i][11]*dp[1][11]);
	//final
	for(i=0;i<8;i++)
	{
		double tmp=0;
		for(j=8;j<16;j++)tmp+=probable[i][j]*dp[2][j];
		dp[3][i]=dp[2][i]*tmp;
	}
	for(i=8;i<16;i++)
	{
		double tmp=0;
		for(j=0;j<8;j++)tmp+=probable[i][j]*dp[2][j];
		dp[3][i]=dp[2][i]*tmp;
	}
	for(i=0;i<16;i++)
	{
		printf("%s p=%.2f%%\n",nation[i],dp[3][i]*100);
	}
	return 0;
}
