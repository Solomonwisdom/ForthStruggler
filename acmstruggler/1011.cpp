////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-08-06 20:27:00
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1011
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:1724KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=120;
int N,M;
struct room{
	int bug,p;
};
room rs[maxn];
int dp[maxn][maxn];
int adj[maxn][maxn];
bool vis[maxn];
void dfs(int root){
	vis[root]=true;
	int num=(rs[root].bug+19)/20;
	for(int i=num;i<=M;i++) dp[root][i]=rs[root].p;
	for(int i=1;i<=adj[root][0];i++){
		int u=adj[root][i];
		if(vis[u]) continue;
		dfs(u);
		for(int j=M;j>=num;j--)
			for(int k=1;k<=M-j;k++)
				if(dp[u][k])
					dp[root][j+k]=dp[root][j+k]>(dp[root][j]+dp[u][k])?dp[root][j+k]:(dp[root][j]+dp[u][k]);
	}
}
int main(void){
	int b,e;
	while(scanf("%d %d",&N,&M)!=EOF&&N!=-1&&M!=-1){
		memset(adj,0,sizeof(adj));
		memset(dp,0,sizeof(dp));
		memset(vis,false,sizeof(vis));
		for(int i=1;i<=N;i++)
			scanf("%d %d",&rs[i].bug,&rs[i].p);
		for(int i=1;i<N;i++){
			scanf("%d %d",&b,&e);
			adj[b][0]++;
			adj[b][adj[b][0]]=e;
			adj[e][0]++;
			adj[e][adj[e][0]]=b;
		}
		if(M==0){
			printf("0\n");
			continue;
		}
		dfs(1);
		printf("%d\n",dp[1][M]);
	}
	return 0;
}