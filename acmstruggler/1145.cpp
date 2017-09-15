////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-17 13:44:28
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1145
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1696KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
double p;
int n;
double dfs(int a,int money)
{
	double temp,mo;
	if(a==n)
	{
		if(p>0.5) return (1+p)*money;
		return 0.5/(1-p)*1.5*money+(0.5-p)/(1-p)*money;
	}
	temp=dfs(a+1,money*2);
	mo=money/temp;
	if(p>mo) return (1+p)/2*temp;
	return (1-mo)/(1-p)*(1+mo)/2*temp+(mo-p)/(1-p)*money;
}
int main(void)
{
	double t,prize;
	while(cin>>n>>p&&n&&p)
	{
		t=dfs(1,1);
		printf("%.3lf\n",t);
	}
	return 0;
}