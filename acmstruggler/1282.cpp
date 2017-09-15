////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-18 20:04:34
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1282
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1620KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int main(void){
	char shu[30]={'0'},rev[30]={'0'},kp[100][30];
	int i,len;
	while(scanf("%s",shu)!=EOF){
		strcpy(rev,shu);
		i=0;
		strcpy(kp[i],shu);
		len=strlen(shu);
		reverse(rev,rev+len);
		
		while(strcmp(shu,rev)!=0){
			i++;
			for(int j=0;j<len;j++)
			{
				rev[j]+=(shu[j]-'0');
				if(rev[j]>'9'){ 
					rev[j]-=10;
					if(j==len-1){ rev[j+1]='1';rev[j+2]='\0';}
					else rev[j+1]++;
				}
			}
			if(rev[len]=='1') len++;
			strcpy(shu,rev);
			reverse(shu,shu+len);
			strcpy(kp[i],shu);
		}
		printf("%d\n",i);
		for(int j=0;j<=i;j++){
			if(j) printf("--->");
			printf("%s",kp[j]);}
		printf("\n");
	}
	return 0;
}