/*1.�жϿɲ����ܡ�����ֻ��Ҫ�������@��<����̵�·�������ɣ�
  ��bfsͨ���ǽ������Ϊ��ķ�ʽ����ˣ�����bfs��
2.������ܣ����ʹ���ֵ��󻯡�
  2.1ֱ��dfs�����ѶȺܴ�����������жϵ�ǰ��·��Ӧ�ý����������ǵ���<��Ϊֹ��
     ��Ϊ���ܻ���ʱ�䣬���Ե�������һ���鱦���ڻص���<�������������������<������
     ���鱦�ͳ�����ָ����ʱ�䣩���Ҳ��ܱ�ǽڵ��ѷ��ʣ���Ϊһ���ڵ�����ظ����ʡ�
     ��Ȼ���Ա�ǽڵ㱻�����˶��ٴΣ����ñ�ǽڵ���ʵĴ�����Ҳ���Խ��м�֦������
     �����������������Ҳ��������ǳ�ʱ����Ϊ���нڵ������2500����dfs����ȿ�
     ��̫����ҽڵ�����ظ���
  2.2����ϸ�۲���Ŀ����ʵ���ǵ�Ŀ��ֻ��'@','<','A'~'J'�й�ϵ�����Ǵ�'@'��ʼ����
     �����ܶ��value��'A'~'J'����'<'��û�г�ʱ���������ǵ��������ʱҲ��12������
     ˼����˵�󲿷ֽ���'.','*'.�������ֻ��Ҫ������12���ڵ�֮�����̾��룬������
     �ķ���̾��벻��Ҫ�ܣ���Ϊ��Щ����̾���ﵽ����ͬ����Ч�������Ǵ�һ���ڵ㵽��
     һ���ڵ㣬��ȴ�����˸����ʱ�䡣
  2.3��ˣ����ǿ������2.2�е��ٲ��ֽڵ�֮�����̵�·�������������ڵ�֮���ʱ�䣨��
     �����ʱ�������Ŀ�и�����ʱ�䣬���ǿ�����Ϊ���ɴ��Ȼ������Щ�ڵ�ͽڵ�֮���
     ������Խ���һ������ͼ����Щ��̾��������ͬ��1�еķ�������'@'��ʼ�Ը�����ͼ��
     ��dfs��ͬʱ���ݳ�ʱʱ��������ܵļ�ֵ���м�֦��
3.��Ŀ�е��������⣬��Ŀ�������൱����һ��Χǽ�����������ݲ���������ˡ�����Ŀ�е�W,H
  Ҳ���ó���*/
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
/*/*һ����BFS��DFS��������������Ŀ��
���⣺��һ��n*m��castle��Ȼ������ĳЩ�����Щ���أ�ÿ�����ض��Ǿ��в�ͬ�������ֵ������һ��������ڴ���ʣ��tʱ�䣬����ô�������ڸ�����ʱ����
������ı��ؼ�ֵ�����Ǿ���̰����
��ŵ�˼·���������Ǳ���bfs��bfs���ĳ���㣨��ʵ����3�֣���ڡ����ڡ����أ�������һ���㣨Ҳ����3�֣�֮������·��
Ȼ�����ڴ���ʼ����dfs�������Ƚϡ�
�㷨��ȷ����ȷ���ģ���Ϊ���ڱ�֤���·��ǰ���£���������dfs�����ѵ�����һ��������о����ܵ����㷨ʧЧ�Ŀ����ԣ�����A������C�����·�����˱���B��
��ô��DFS�Ĺ����У����DFS��A->C����ô��Ϊ���ڱȽϵĹ��̣����϶�����ѡ��A->B->C��������õı��ظ��ࡣ�����dfs��ȫ�����ܵ�dfs.��dfs���˸���֦����

AC���룺*/
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