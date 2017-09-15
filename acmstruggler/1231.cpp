////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-18 11:26:47
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1231
////Problem Title: 
////Run result: Accept
////Run time:858MS
////Run memory:1688KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main(void){
	int i,k,*p,*dp,max,j,c,sum;
	bool flag;
	while(scanf("%d",&k)!=EOF&&k){
		p=new int[k];
		dp=new int[k];
		flag=false;
		for(i=0;i<k;i++) dp[i]=0;
		for(i=0;i<k;i++)
		{
			scanf("%d",&p[i]);
			if(p[i]>=0) flag=true;
			if(i>0) dp[i]=p[i]>(dp[i-1]+p[i])?p[i]:(dp[i-1]+p[i]);
			else dp[i]=p[i];
		}
		max=0;
		if(flag){
			for(i=0;i<k;i++)
				if(max<dp[i]) max=dp[i];
			for(i=0;i<k;i++) if(dp[i]==max) break;
			for(j=0;j<=i;j++){
				sum=0;
				for(c=j;c<=i;c++) sum+=p[c];
				if(sum==max) break;
			}
			printf("%d %d %d\n",max,p[j],p[i]);
		}
		else printf("0 %d %d\n",p[0],p[k-1]);
		delete []p;
		delete []dp;
	}
	return 0;
}