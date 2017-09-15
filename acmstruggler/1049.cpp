////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-15 18:14:54
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1049
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1688KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
int main(void)
{
	int n,u,d,time,height,i;
	while(cin>>n>>u>>d&&n)
	{
		i=1;
		time=height=0;
		while(true){
			time++;
			if(i%2){
				height+=u;
				if(height>=n) break;
			}
			else
				height-=d;
			i++;
		}
		cout<<time<<endl;
	}
	return 0;
}