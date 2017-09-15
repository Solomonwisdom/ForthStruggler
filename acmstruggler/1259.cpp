////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-25 20:57:40
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1259
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1616KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main(void)
{
	int n,m,x,y,mark;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&m);
		mark=2;
		while(m--){
			scanf("%d %d",&x,&y);
			if(x==mark) mark=y;
			else if(y==mark) mark=x;
		}
		printf("%d\n",mark);
	}
	return 0;
}
