////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-14 13:52:33
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1001
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1684KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string.h>
using namespace std;
int main(void)
{
	int sum,n;
	while(cin>>n)
	{
		sum=0;
		for(int i=1;i<=n;i++)
			sum+=i;
		cout<<sum<<endl;
		cout<<endl;
	}
	return 0;
}