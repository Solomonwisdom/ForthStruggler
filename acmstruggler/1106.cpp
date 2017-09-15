////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-25 07:51:08
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1106
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1620KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<algorithm>
using namespace std;
int main(void){
	int res[1500];
	char a[1500];
	int i,fac,len,j;
	while(scanf("%s",a)!=EOF){
		memset(res,0,sizeof(res));
		len=strlen(a);
		for(i=0;i<len&&a[i]=='5';i++);
		j=fac=0;
		while(i<len){
			if(a[i]=='5'){
				res[j++]=fac;
				fac=0;
				for(;i<len&&a[i]=='5';i++);
			}
			else if(a[i]<='9'&&a[i]>='0'){
				fac=fac*10+a[i]-'0';
				if(i==len-1) res[j++]=fac;
				i++;
			}
		}
		sort(res,res+j);
		for(i=0;i<j-1;i++) printf("%d ",res[i]);
		printf("%d\n",res[j-1]);
	}
	return 0;
}