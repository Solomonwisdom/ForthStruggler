////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-14 16:27:41
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1014
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1676KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string.h>
using namespace std;
int gcd(int a,int b)
{
	if(a%b==0) return b;
	else return gcd(b,a%b);
}
int main(void)
{
	int step,mod,r;
	while(cin>>step>>mod){
		r=gcd(step,mod);
	    if(r==1) printf("%10d%10d    Good Choice\n\n",step,mod);
	    else printf("%10d%10d    Bad Choice\n\n",step,mod);
	}
	return 0;
}