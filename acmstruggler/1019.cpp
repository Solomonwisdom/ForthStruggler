////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-09-06 18:24:16
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1019
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1724KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
using namespace std;
int gcd(int a,int b){
	int r;
	while(a%b!=0){
		r=a%b;
		a=b;
		b=r;
	}
	return b;
}
int lcm(int a,int b){
	return a/gcd(a,b)*b;
}
int main(void){
	int n,m,tem,ans;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&m);
		ans=1;
		while(m--){
			scanf("%d",&tem);
			ans=lcm(ans,tem);
		}
		printf("%d\n",ans);
	}
	return 0;
}