////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-20 16:12:34
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1390
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1620KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int main(void){
	int m,n,len;
	char bin[50];
	bool flag;
	scanf("%d",&m);
	while(m--){
		scanf("%d",&n);
		itoa(n,bin,2);
		len=strlen(bin);
		reverse(bin,bin+len);
		flag=true;
		for(int i=0;i<len;i++)
			if(bin[i]=='1') {
				if(flag) flag=false;
				else printf(" ");
				printf("%d",i);
			}
		printf("\n");
	}
	return 0;
}