////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-18 16:24:16
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1260
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1780KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main(void){
	int n,k,*t1,*t2,*dp;
	int h,m,s;
	char c,t;
	cin>>n;
	while(n--){
		scanf("%d",&k);
		t1=new int[k];
		t2=new int[k-1];
		dp=new int[k];
		for(int i=0;i<k;i++)
			scanf("%d",&t1[i]);
		for(int i=0;i<k-1;i++)
			scanf("%d",&t2[i]);
		dp[0]=t1[0];
		if(k>1)dp[1]=(dp[0]+t1[1])>t2[0]?t2[0]:(dp[0]+t1[1]);
		for(int i=2;i<k;i++)
			dp[i]=(dp[i-1]+t1[i])>(dp[i-2]+t2[i-1])?(dp[i-2]+t2[i-1]):(dp[i-1]+t1[i]);
		h=8+dp[k-1]/3600;
		m=dp[k-1]%3600/60;
		s=dp[k-1]%60;
		if(h<12||(h==12&&m==0&&s==0))
		{
			c='a';
			t='m';
		}
		else{
			c='p';
			t='m';
		}
		printf("%02d:%02d:%02d %c%c\n",h,m,s,c,t);
	}
	return 0;
}