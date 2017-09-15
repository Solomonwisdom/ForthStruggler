////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-21 17:22:19
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1709
////Problem Title: 
////Run result: Accept
////Run time:171MS
////Run memory:2376KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cmath>
using namespace std;
int main(void)
{
	int n,*qua,i,sum,*fac,*res,count;
	while(scanf("%d",&n)!=EOF){
		sum=count=0;
		qua=new int[n];
		for(i=0;i<n;i++){
			scanf("%d",&qua[i]);
			sum+=qua[i];}
		res=new int[sum+1];
		fac=new int[sum+1];
		memset(res,0,sizeof(int)*(sum+1));
		memset(fac,0,sizeof(int)*(sum+1));
		res[0]=1;
		res[qua[0]]=1;
		for(int i=1;i<n;i++){
			for(int j=0;j<=sum;j++){
					if(j+qua[i]<=sum) fac[j+qua[i]]+=res[j];
					fac[j]+=res[j];
					fac[abs(j-qua[i])]+=res[j];
			}
			for(int k=0;k<=sum;k++){
				res[k]=fac[k];
				fac[k]=0;
			}
		}
		for(int i=0;i<=sum;i++)
			if(res[i]==0)
				count++;
		printf("%d\n",count);
		if(count==0) continue;
		bool flag=false;
		for(int i=0;i<=sum;i++)
			if(res[i]==0){
				if(flag) printf(" ");
				else flag=true;
				printf("%d",i);
			}
		printf("\n");
		delete []qua;
		delete []fac;
		delete []res;
	}
	return 0;
}