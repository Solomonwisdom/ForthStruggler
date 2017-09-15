////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-08-19 20:03:52
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1016
////Problem Title: 
////Run result: Accept
////Run time:468MS
////Run memory:1736KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
using namespace std;
int num[21],n;
bool mark[21];
int prime[12]={2,3,5,7,11,13,17,19,23,29,31,37};
bool isprime(int a){
	for(int i=0;i<12;i++)
		if(prime[i]==a)
			return true;
	return false;
}
bool dfs(int pre,int cur,int pos){
	if(!isprime(pre+cur))
		return false;
	num[pos]=cur;
	if(pos==n&&isprime(cur+1)){
		for(int i=1;i<n;i++)
			printf("%d ",num[i]);
		printf("%d\n",num[n]);
		return true;
	}
	mark[cur]=false;
	for(int i=2;i<=n;i++)
		if(mark[i]&&dfs(cur,i,pos+1)) break;
	mark[cur]=true;
	return false;
}
int main(void){
	int count=1;
	while(scanf("%d",&n)!=EOF){
		memset(mark,true,sizeof(mark));
		num[1]=1;
		printf("Case %d:\n",count++);
		if(n==1) printf("1\n");
		for(int i=2;i<=n;i++)
			dfs(1,i,2);
		printf("\n");
	}
	return 0;
}