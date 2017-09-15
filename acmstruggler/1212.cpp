////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-25 19:31:34
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1212
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1612KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string.h>
using namespace std;
int main(void){
	char shu[1001];
	int b,mod;
	while(scanf("%s %d",shu,&b)!=EOF){
		int len=strlen(shu);
		mod=0;
		for(int i=0;i<len;i++)
			mod=((mod*10)%b+(shu[i]-'0')%b)%b;
		printf("%d\n",mod);
	}
	return 0;
}