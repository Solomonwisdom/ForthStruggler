////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-21 17:37:36
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1719
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1624KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cmath>
using namespace std;
int main(void)
{
	_int64 a;
	while(scanf("%I64d",&a)!=EOF){
		if(a==0){
			printf("NO!\n");
			continue;
		}
		_int64 t=a+1;
		while(t%2==0) t/=2;
		while(t%3==0) t/=3;
		if(t==1) printf("YES!\n");
		else printf("NO!\n");
	}
	return 0;
}