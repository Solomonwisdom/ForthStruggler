////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-17 20:31:54
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1219
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1716KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string.h>
using namespace std;
int main(void){
	char s[100001];
	int len,count[26];
	while(gets(s))
	{
		for(int i=0;i<26;i++) count[i]=0;
		len=strlen(s);
		for(int i=0;i<len;i++)
			if(s[i]>='a'&&s[i]<='z') count[s[i]-'a']++;
		for(int i=0;i<26;i++)
			printf("%c:%d\n",'a'+i,count[i]);
		printf("\n");
	}
	return 0;
}