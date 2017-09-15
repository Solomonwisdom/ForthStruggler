////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-17 16:05:39
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1178
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1628KB
//////////////////System Comment End//////////////////
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
	int n,bit;
	double sum;
	while(scanf("%d",&n)!=EOF&&n)
	{
	    sum = (double)( 1.0*(n+2)*(n+1)*n/6.0);
	    bit = (int)log10(sum);
	    sum /= pow(10.0, (1.0*bit));//这个问题貌似遇到过，中间用doube赋下值
	    printf("%0.2lfE%d\n",sum,bit);
	}
}