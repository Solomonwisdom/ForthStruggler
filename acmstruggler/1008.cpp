////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-14 11:13:58
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1008
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1700KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main(void)
{
	int N,i,*floor,time;
	while((cin>>N)&&N)
	{
		time=0;
		floor=new int[N+1];
		floor[0]=0;
		for(i=1;i<=N;i++)
		{
			cin>>floor[i];
			if(floor[i-1]<floor[i])
				time+=(6*(floor[i]-floor[i-1])+5);
			else time+=(4*(floor[i-1]-floor[i])+5);
		}
		cout<<time<<endl;
	}
	return 0;
}