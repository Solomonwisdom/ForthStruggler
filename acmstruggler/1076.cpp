////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-15 22:37:06
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1076
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1684KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int isleap(int y)
{
	if((y%4==0&&y%100!=0)||y%400==0)
		return 1;
	return 0;
}
int main(void)
{
	int n,Y,N;
	cin>>n;
	while(n--)
	{
		cin>>Y>>N;
		for(int i=0;i<N;)
			i+=isleap(Y++);
		cout<<Y-1<<endl;
	}
	return 0;
}