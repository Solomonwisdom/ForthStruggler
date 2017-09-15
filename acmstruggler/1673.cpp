////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-21 14:40:39
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1673
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1684KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main(void)
{
	int max,min,t,n,x;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			if(i==0) max=min=x;
			else {
				max=max>x?max:x;
				min=min<x?min:x;
			}
		}
		printf("%d\n",(max-min)*2);
	}
	return 0;
}