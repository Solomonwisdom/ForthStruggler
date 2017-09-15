////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-17 10:18:18
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1128
////Problem Title: 
////Run result: Accept
////Run time:124MS
////Run memory:2592KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main(void)
{
	int sum,i,j;
	bool a[1000001]={false};
	for(i=1,j;i<=1000000;i++)
	{
		j=i;
		for(sum=j;j;j/=10)
			sum+=j%10;
		if(sum>1000000) break;
		a[sum]=true;
		if(!a[i]) printf("%d\n",i);		
	}
	for(;i<=1000000;i++)
		if(!a[i]) printf("%d\n",i);
	return 0;
}