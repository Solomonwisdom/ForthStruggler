////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-18 16:53:26
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1266
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1664KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int main(void){
	int n,start,end,len;
	char num[50];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>num;
		if(num[0]!='-') start=0;
		else start=1;
		len=strlen(num);
		if(num[len-1]=='0') {
			int j=0;
			while(num[j]!='0') j++;
			end=j;}
		else end=len;
		reverse(num+start,num+end);
		printf("%s\n",num);
	}
	return 0;
}