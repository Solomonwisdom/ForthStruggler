////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-21 18:35:19
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1721
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1620KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cmath>
using namespace std;
int main(void)
{
	int num[9];
	while(scanf("%d",&num[1])!=EOF&&num[1]>=0){
		for(int i=2;i<=8;i++)
			scanf("%d",&num[i]);
		num[1]+=num[6];
		num[2]+=num[5];
		num[3]+=num[8];
		num[4]+=num[7];
		if((num[1]-num[2])==(num[4]-num[3]) )
			printf("All the seeds can be cleared away!\n");
		else printf("Sorry,it can't be cleared away!\n");
	}
	return 0;
}