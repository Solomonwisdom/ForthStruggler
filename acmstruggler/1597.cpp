////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-21 14:33:52
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1597
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1684KB
//////////////////System Comment End//////////////////
#include <iostream>
#include<cmath>
using namespace std;
int main(void)
{
	_int64 k,n,x;
	cin>>k;
	while(k--){
		scanf("%I64d",&n);
		x=((_int64)sqrt(1+8.0*(n-1))-1)/2;
		n-=x*(x+1)/2;
		printf("%I64d\n",n%9==0?9:n%9);
	}
	return 0;
}