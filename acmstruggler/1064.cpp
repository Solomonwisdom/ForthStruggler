////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-15 20:19:03
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1064
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1692KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string.h>
using namespace std;
int main(void)
{
	double n,sum=0;
	for(int i=0;i<12;i++){
		cin>>n;
		sum+=n;}
	printf("$%.2lf\n",sum/12);
	return 0;
}