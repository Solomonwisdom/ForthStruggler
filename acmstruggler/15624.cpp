////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-21 12:01:49
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1562
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1680KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main(void)
{
	int a,b,c,i,t;
	cin>>t;
	while(t--){
		scanf("%d %d %d",&a,&b,&c);
		for(i=1000;i<=9999;i++)
			if(i%a==0&&(i+1)%b==0&&(i+2)%c==0) break;
		if(i>9999)printf("Impossible\n");
		else printf("%d\n",i);
	}
	return 0;
}