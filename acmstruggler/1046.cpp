////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-15 14:14:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1046
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1684KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main(void)
{
	int N,m,n;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>m>>n;
		if(m%2==0||n%2==0) printf("Scenario #%d:\n%.2lf\n\n",i+1,double(m*n));
		else printf("Scenario #%d:\n%.2lf\n\n",i+1,double(m*n)-1+1.41);
	}
	return 0;
}