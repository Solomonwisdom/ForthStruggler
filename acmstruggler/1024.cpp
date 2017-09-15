////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-30 09:37:56
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1024
////Problem Title: 
////Run result: Accept
////Run time:436MS
////Run memory:2792KB
//////////////////System Comment End//////////////////
#include<iostream>
#define MIN_SUM 0x80000000
using namespace std;
int main(char argc,char *argv[])
{
	int m,n,*S,*curr_best,*pre_best;
	int i,j,maxs;
	while(scanf("%d %d",&m,&n)!=EOF){
		S=new int[n+1];
		curr_best=new int[n+1];
		pre_best=new int[n+1];
		curr_best[0]=pre_best[0]=0;
		for(i=1;i<=n;i++){
			scanf("%d",&S[i]);
			curr_best[i]=0;
			pre_best[i]=0;
		}
		for(i=1;i<=m;i++)
		{
			maxs=MIN_SUM;
			for(j=i;j<=n;j++){
				curr_best[j]=(curr_best[j-1]>pre_best[j-1]?curr_best[j-1]:pre_best[j-1])+S[j];
				pre_best[j-1]=maxs;
				maxs=maxs>curr_best[j]?maxs:curr_best[j];
			}
			pre_best[j-1]=maxs;
		}
		printf("%d\n",maxs);
		delete []S;
		delete []curr_best;
		delete []pre_best;
	}
	return 0;
}