/*1.判断可不可能。我们只需要计算出从@到<的最短的路径数即可，
  而bfs通常是解决这类为题的方式，因此，进行bfs。
2.如果可能，如何使其价值最大化。
  2.1直接dfs搜索难度很大，首先是如何判断当前的路径应该结束（并不是到‘<’为止，
     因为可能还有时间，可以到其他的一个珠宝，在回到‘<’处，而如果不经过‘<’到那
     个珠宝就超过了指定的时间），且不能标记节点已访问，因为一个节点可以重复访问。
     当然可以标记节点被访问了多少次，利用标记节点访问的次数，也可以进行剪枝。就算
     是以上问题解决，最后也极大可能是超时，因为题中节点数多达2500，即dfs的深度可
     能太深，并且节点可以重复。
  2.2而仔细观察题目，其实我们的目的只与'@','<','A'~'J'有关系（就是从'@'开始经过
     尽可能多的value（'A'~'J'）到'<'且没有超时），而他们的总数最大时也就12个，意
     思就是说大部分将是'.','*'.因此我们只需要关心这12个节点之间的最短距离，而其他
     的非最短距离不需要管，因为这些非最短距离达到的是同样的效果，就是从一个节点到另
     一个节点，但却花费了更多的时间。
  2.3因此，我们可以求出2.2中的少部分节点之间的最短的路径，即这两个节点之间的时间（如
     果这个时间大于题目中给出的时间，我们可以认为不可达），然后用这些节点和节点之间的
     距离可以建立一个无向图。这些最短距离的求法如同在1中的方法。从'@'开始对该无向图进
     行dfs，同时根据超时时间和最大可能的价值进行剪枝。
3.题目中的数据问题，题目的例子相当于有一个围墙，而可能数据并不总是如此。从题目中的W,H
  也看得出。*/
#include<iostream>
#include<queue>
using namespace std;
char map[50][50];
int distan[12][12];
int jewels[12][3];
int mark[50][50];
int visit[12];
int sx,sy,ex,ey,dijige,youjige,cancollect,maxjewels,jieshu;
int u,n,m,t,zhubao,flag;
struct node
{
	int x,y,step;
}w,p;
int dir[4][2]={1,0,-1,0,0,1,0,-1};
int bfs(int qx,int qy,int mx,int my)
{
	queue<node> q;
	w.x=qx;w.y=qy;w.step=0;
	while(!q.empty())
		q.pop();
	q.push(w);
	while(!q.empty())
	{
		p=q.front();
		q.pop();
		if(p.x==mx&&p.y==my)
			return p.step;
		for(int i=0;i<4;i++)
		{
			w.x=p.x+dir[i][0];
			w.y=p.y+dir[i][1];
			w.step=p.step+1;
			if(w.x>=0&&w.x<n&&w.y>=0&&w.y<m&&map[w.x][w.y]!='*'&&mark[w.x][w.y]==0)
			{
				mark[w.x][w.y]=1;
				q.push(w);
			}
		}
	}
	return 1000001;
}
void dfs(int weizhi,int step,int jewel)
{
	if(step<0) return;
	if(jieshu==1) return;
	if(jewel==cancollect&&step>=0&&weizhi==zhubao+1)
	{
		maxjewels=jewel;
		flag=1;
		jieshu=1;
		return;
	}
	if(weizhi==zhubao+1&&step>=0)
	{
		flag=1;
		if(jewel>maxjewels)
			maxjewels=jewel;
		return;
	}
	for(int i=0;i<zhubao+2;i++)
	{
		if(visit[i]==0)
		{
			visit[i]=1;
			dfs(i,step-distan[weizhi][i],jewel+jewels[i][2]);
			visit[i]=0;
		}
	}
	return;
}
	
int main()
{
	cin>>u;
	youjige=u;
	dijige=1;
	while(u--)
	{
		memset(jewels,0,sizeof(jewels));
		cin>>m>>n>>t>>zhubao;
		for(int i=0;i<zhubao;i++)
			cin>>jewels[i][2];
		memset(distan,1000001,sizeof(distan));
		memset(mark,0,sizeof(mark));
		memset(visit,0,sizeof(visit));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>map[i][j];
				if(map[i][j]=='@')
				{
					sx=i;
					sy=j;
				}
				if(map[i][j]=='<')
				{
					ex=i;
					ey=j;
				}
				if(map[i][j]>='A'&&map[i][j]<='J')
				{
					jewels[map[i][j]-'A'][0]=i;
					jewels[map[i][j]-'A'][1]=j;
				}
			}
		}
		cancollect=0;
        for(int i=0;i<zhubao;i++)
		{
			distan[zhubao][i]=bfs(sx,sy,jewels[i][0],jewels[i][1]);
			memset(mark,0,sizeof(mark));
			distan[zhubao+1][i]=bfs(ex,ey,jewels[i][0],jewels[i][1]);
			memset(mark,0,sizeof(mark));
			distan[i][zhubao]=distan[zhubao][i];
			distan[i][zhubao+1]=distan[zhubao+1][i];
			if(distan[zhubao][i]!=1000001)
				cancollect+=jewels[i][2];
		}
		distan[zhubao][zhubao+1]=bfs(sx,sy,ex,ey);
		memset(mark,0,sizeof(mark));
		distan[zhubao+1][zhubao]=distan[zhubao][zhubao+1];
		for(int i=0;i<zhubao;i++)
			for(int j=0;j<zhubao;j++)
			{
				if(i<j)
				{
					distan[i][j]=bfs(jewels[i][0],jewels[i][1],jewels[j][0],jewels[j][1]);
					memset(mark,0,sizeof(mark));
				}
				else
					distan[i][j]=distan[j][i];
			}
			
		visit[zhubao]=1;
		maxjewels=0;
		flag=0;
		jieshu=0;
		dfs(zhubao,t,0);
		cout<<"Case "<<dijige<<':'<<endl;
		if(flag==1)
			cout<<"The best score is "<<maxjewels<<'.'<<endl;
		else
			cout<<"Impossible"<<endl;
		if(dijige<youjige)
			cout<<endl;
		dijige++;
	}
	return 0;
}
/*/*一道将BFS和DFS联合起来做的题目。
题意：有一个n*m的castle？然后里面某些点放了些宝藏，每个宝藏都是具有不同的自身价值，现在一个人在入口处，剩下t时间，问怎么样才能在给定的时间下
获得最大的宝藏价值（就是尽量贪婪）
大概的思路：对整个城堡做bfs，bfs求得某个点（其实包含3种，入口。出口。宝藏）到另外一个点（也是那3种）之间的最短路。
然后从入口处开始进行dfs搜索，比较。
算法正确性是确定的，因为：在保证最短路的前提下，我们做的dfs可以搜到任意一种情况，感觉可能导致算法失效的可能性：宝藏A到宝藏C的最短路经历了宝藏B，
那么在DFS的过程中，如果DFS了A->C，那么因为存在比较的过程，最后肯定优先选择A->B->C，这样获得的宝藏更多。这里的dfs是全部可能的dfs.（dfs加了个剪枝）。

AC代码：
#include<iostream>
#include<cmath>
#include<map>
#include<cstring>
#include<cstdio>
#include<cstdio>
#include<cassert>
#include<vector>
#include<string>
#include<algorithm>
#include<list>
#include<set>
#include<queue>
#include<stack>
#include<bitset>
#define LL long long
#define maxab(a,b) (a)>(b)?(a):(b)
#define LL long long
#define lowbit(x) (x&(-x))
using namespace std;
const int MAXN=55;
char maze[MAXN][MAXN];
int vis[MAXN][MAXN],step[MAXN][MAXN];
int f[MAXN][MAXN],vis_[MAXN],val[MAXN];
int fx[4]={0,0,1,-1};
int fy[4]={1,-1,0,0};
int n,m,l,w;
int sum,ans;
struct node{
  int x,y;
};
queue<node>q;
void bfs(int x,int y,int s){
   while(!q.empty()) q.pop();
   node tmp;
   tmp.x=x,tmp.y=y;
   q.push(tmp);
   vis[x][y]=1,step[x][y]=0;
   while(!q.empty()){
      node p=q.front();
      q.pop();
      for(int i=0;i<4;++i){
         int newx=p.x+fx[i];
         int newy=p.y+fy[i];
         node pp;
         pp.x=newx,pp.y=newy;
         if(newx<0 || newx>=n || newy<0 || newy>=m) continue;
         if(maze[newx][newy]=='*' || vis[newx][newy]) continue;
         step[newx][newy]=step[p.x][p.y]+1;
         vis[newx][newy]=1;
         if(maze[newx][newy]=='@') f[s][0]=step[newx][newy];
         else if(maze[newx][newy]=='<') f[s][w+1]=step[newx][newy];
         else if(maze[newx][newy]>='A' && maze[newx][newy]<='Z') f[s][maze[newx][newy]-'A'+1]=step[newx][newy];
         q.push(pp);
      }
   }
}
void dfs(int x,int y,int t){
  if(t>l || ans==sum) return ;
  if(x==w+1 && y>ans) ans=y;
  for(int i=1;i<=w+1;++i){
    if(!vis_[i] && f[x][i]){
      vis_[i]=1;
      dfs(i,y+val[i],t+f[x][i]);
      vis_[i]=0;
    }
  }
}
int main(){
   int T,x=0;
   scanf("%d",&T);
   while(T--){
     sum=0,ans=-1;
     scanf("%d%d%d%d",&m,&n,&l,&w);
     for(int i=1;i<=w;++i) scanf("%d",&val[i]),sum+=val[i];
     val[w+1]=0;
     getchar();
     for(int i=0;i<n;++i){
       for(int j=0;j<m;++j)
         scanf("%c",&maze[i][j]);
         getchar();
     }
     memset(vis,0,sizeof(vis));
     memset(vis_,0,sizeof(vis_));
     memset(f,0,sizeof(f));
     for(int i=0;i<n;++i)
       for(int j=0;j<m;++j){
          memset(vis,0,sizeof(vis));
          memset(step,0,sizeof(step));
          if(maze[i][j]=='@') bfs(i,j,0);
          else if(maze[i][j]>='A' && maze[i][j]<='Z') bfs(i,j,maze[i][j]-64);
          else if(maze[i][j]=='<') bfs(i,j,w+1);
       }
     vis_[0]=1;
     dfs(0,0,0);
     printf("Case %d:\n",++x);
     if(ans>=0) printf("The best score is %d.\n",ans);
     else printf("Impossible\n");
     if(T)  printf("\n");
   }
}*/