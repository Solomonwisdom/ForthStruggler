////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-14 16:06:50
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1013
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1672KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string.h>
using namespace std;
int main(void)
{
	char a[10000];
	int sum,len;
	while(cin>>a&&strcmp(a,"0"))
	{
		sum=0;
		len=strlen(a);
		for(int i=0;i<len;i++)
			sum+=a[i]-'0';
		cout<<(sum-1)%9+1<<endl;
	}
	return 0;
}