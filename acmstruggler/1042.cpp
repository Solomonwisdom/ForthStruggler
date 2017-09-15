////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-21 20:19:17
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1042
////Problem Title: 
////Run result: Accept
////Run time:2152MS
////Run memory:1776KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main(void)
{
	int s[40001];
	int n,t,i,j,r,len;
	while(scanf("%d",&n)!=EOF){
		if(n==1||n==0){
			printf("1\n");
			continue;
		}
		memset(s,0,sizeof(s));
		s[0]=1;
		for(i=2,len=0;i<=n;i++){
			r=0;
			for(j=0;j<=len;j++){
				s[j]=s[j]*i+r;
				r=s[j]/10;
				s[j]=s[j]%10;
				if(j==len){
					len+=4;
					break;
				}
			}
		}
		while(s[j]==0) j--;
		while(j>=0) printf("%d",s[j--]);
		printf("\n");
	}
	return 0;
}