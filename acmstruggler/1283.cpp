////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-26 08:10:20
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1283
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1620KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string.h>
using namespace std;
int main(void)
{
	int m1,m2,r1,r2,r3;
	char guide[201];
	while(scanf("%d %d",&m1,&m2)!=EOF){
		getchar();
		scanf("%s",guide);
		r1=r2=r3=0;
		for(int i=0;i<strlen(guide);i++)
			switch(guide[i]){
			case'A':
				r1=m1;
				break;
			case'B':
				r2=m2;
				break;
			case'C':
				m1=r3;
				break;
			case'D':
				m2=r3;
				break;
			case'E':
				r3=r1+r2;
				break;
			case'F':
				r3=r1-r2;
				break;
			}
		printf("%d,%d\n",m1,m2);
	}
	return 0;
}
