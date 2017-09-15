////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-26 08:25:07
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1287
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:1932KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string.h>
using namespace std;
int main(void)
{
	int n,*p;
	char mark;
	while(scanf("%d",&n)!=EOF){
		p=new int[n];
		for(int i=0;i<n;i++)
			scanf("%d",&p[i]);
		for(int i='A',j;i<='Z';i++){
			for(j=0;j<n;j++)
				if((i^p[j])>'Z'||(i^p[j])<'A')
					break;
			if(j==n){
				mark=i;
				break;
			}
		}
		for(int i=0;i<n;i++)
			printf("%c",(p[i]^mark));
		printf("\n");
	}
	return 0;
}
