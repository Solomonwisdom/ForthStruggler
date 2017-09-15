////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-21 16:05:21
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1701
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1700KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main(void)
{
	int t,n;
	double p,q;
	cin>>t;
	while(t--){
		cin>>p>>q;
		n=1;
		while(int((p*n)/100)>=int((q*n)/100))
			n++;
		printf("%d\n",n);
	}
	return 0;
}