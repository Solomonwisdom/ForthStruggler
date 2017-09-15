////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-21 19:42:16
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1792
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1624KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main(void)
{
	int a,b;
	while(scanf("%d %d",&a,&b)!=EOF){
		printf("%d %d\n",a*b-a-b,(a-1)*(b-1)/2);
	}
	return 0;
}