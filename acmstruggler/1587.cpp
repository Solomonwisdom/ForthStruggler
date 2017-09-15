////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-21 13:38:03
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1587
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1620KB
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
	int n,m,min,t;
	while(scanf("%d %d",&n,&m)!=EOF){
		scanf("%d",&t);
		min=t;
		n--;
		while(n--){
			scanf("%d",&t);
			min=min<t?min:t;}
		printf("%d\n",m/min);
	}
	return 0;
}