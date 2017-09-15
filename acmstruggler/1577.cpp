////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-21 13:26:42
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1577
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:1628KB
//////////////////System Comment End//////////////////
#include <iostream>
#include<cmath>
using namespace std;
int gcd(int a,int b)
{
	int r;
	while(b){
		r=b;
		b=a%b;
		a=r;
	}
	return a;
}
int main(void)
{
	int len,sx,sy,px,py;
	while(scanf("%d",&len)!=EOF&&len){
		scanf("%d %d %d %d",&sx,&sy,&px,&py);
		if(px<-len||px>len||py>len||py<-len){
			printf("Out Of Range\n");
			continue;
		}
		px-=sx;
		py-=sy;
		if(abs(px)==1||abs(py)==1){
			printf("Yes\n");
			continue;
		}
		if(gcd(abs(px),abs(py))==1) 
			printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}