////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-22 15:00:31
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2100
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1616KB
//////////////////System Comment End//////////////////
#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main(void)
{
    char s1[202],s2[202],sum[203];
	int len1,len2,max,min,i;
	int jia;
	while(scanf("%s %s",s1,s2)!=EOF){
		memset(sum,'0',sizeof(sum));
		len1=strlen(s1);
		len2=strlen(s2);
		reverse(s1,s1+len1);
		reverse(s2,s2+len2);
		min=len1<len2?len1:len2;
		max=len1>len2?len1:len2;
		jia=0;
		for(i=0;i<min;i++){
			sum[i]=s1[i]+s2[i]-'A'+jia;
			if(sum[i]>'Z'){
				sum[i]-=26;
				jia=1;
			}
			else jia=0;
		}
		if(len1<len2){
			while(i<max){
				sum[i]=s2[i]+jia;
				if(sum[i]>'Z'){
					sum[i]-=26;
				    jia=1;
				}
				else jia=0;
				i++;
			}
			if(jia) sum[i]='B';
		}
		else{
			while(i<max){
				sum[i]=s1[i]+jia;
				if(sum[i]>'Z'){
					sum[i]-=26;
				    jia=1;
				}
				else jia=0;
				i++;
			}
			if(jia) sum[i]='B';
		}
		i=202;
		while(sum[i]=='0'||sum[i]=='A') i--;
		while(i>=0)
			printf("%c",sum[i--]);
		printf("\n");
	}
    return 0;
}