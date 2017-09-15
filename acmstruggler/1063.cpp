////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-24 10:18:20
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1063
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:1672KB
//////////////////System Comment End//////////////////
#include <iostream>
#include<cstring>
using namespace std;
char op[4]={'.','!','X','#'};
int main(void)
{
    
	char real[8];
	int n,i,j,k,len,lp;
	int mul[200];
	while(cin>>real>>n){
		len=strlen(real);
		for(i=len-1;i>=0;i--)
			if(real[i]=='.') 
				break;
		if(i==-1) lp=0;
		else lp=n*(len-1-i);
		memset(mul,0,sizeof(mul));
		k=0;
		for(i=0;i<len;i++){
			if(real[i]=='.')
				continue;
			k=k*10+real[i]-'0';
		}
		int temp=k;
		j=0;
		while(temp){
			mul[j++]=temp%10;
			temp/=10;
		}
		len=j;
		int jia=0,ext;
		for(i=0;i<n-1;i++){
			for(j=0;j<len;j++){
				mul[j]*=k;
				mul[j]+=jia;
				jia=mul[j]/10;
				mul[j]%=10;
			}
			ext=0;
			while(jia){
				mul[j+ext]+=jia%10;
				jia/=10;
				ext++;
			}
			len+=ext;
		}
		for(i=len-1;i>=lp;i--)
			printf("%d",mul[i]);
		for(i=0;i<lp;i++)
			if(mul[i]!=0) break;
		if(i!=lp&&lp){
			printf(".");
			for(j=lp-1;j>=i;j--)
				printf("%d",mul[j]);
		}
		printf("\n");
	}
    return 0;
}