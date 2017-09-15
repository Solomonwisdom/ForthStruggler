////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-14 13:45:42
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1012
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1668KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string.h>
using namespace std;
int main(void)
{
	int n=1;
	double e=0;
	cout<<"n e"<<endl;
	cout<<"- -----------"<<endl;
	for(int i=0;i<=9;i++)
	{
		if(i!=0) n*=i;
		e+=1.0/n;
		if(i>=3) printf("%d %.9lf\n",i,e);
		else cout<<i<<' '<<e<<endl;
	}
	return 0;
}