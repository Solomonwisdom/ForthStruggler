////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-20 17:00:17
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1395
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1632KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main(void){
	int n,i,j;
	while(scanf("%d",&n)!=EOF){
		if(n%2==0||n==1){
			printf("2^? mod %d = 1\n",n);
			continue;}
		for(i=2,j=1;;i=(i%n)*2,j++)
			if(i%n==1){
				printf("2^%d mod %d = 1\n",j,n);
				break;
			}
	}
	return 0;
}