////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-08-03 16:17:19
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1018
////Problem Title: 
////Run result: Accept
////Run time:374MS
////Run memory:1628KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main(void){
	int n,num;
	double sum;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&num);
		sum=1;
		for(int i=1;i<=num;i++)
			sum+=log10(double(i));
		printf("%d\n",(int)sum);
	}
	return 0;
}