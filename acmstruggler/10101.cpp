////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-08-03 15:31:07
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1010
////Problem Title: 
////Run result: Accept
////Run time:764MS
////Run memory:1668KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string.h>
using namespace std;

int vis[10][10];//用来记录这个点是否被访问过
char mat[10][10];//用来记录这个点
int ok,T,M,N;//这里的ok是用来记录判断的，如果深搜确认是可以逃出陷阱，ok被标记为1

void visit(int i,int j,int cur)//（i，j）为当前访问的坐标，cur指访问点（i，j）是第cur步，刚开始cur为0
{
    if(cur>T||ok==1) return;//如果步数超过了T，理所当然要退出啦。或者如果之前的方案确定可以逃出陷阱，理所当然要退出啦。
    else if(cur==T)  {//如果当前步数为T，那么要判断当前是否到了门口
        if(mat[i][j]=='D')//是的话，令ok=1
            ok=1;
        return;
    }
    else if(mat[i][j]=='.'||mat[i][j]=='S'){  //如果当前访问的格子合法（不要漏了“S”，不然第一次的访问将失效）
        vis[i][j]=1;  //做上标记
        if(i+1>=0&&i+1<N&&j>=0&&j<M&&vis[i+1][j]==0)  visit(i+1,j,cur+1);  //判断下一个格子是否在定义域内且是否被标记过，是，访问
        if(i-1>=0&&i-1<N&&j>=0&&j<M&&vis[i-1][j]==0)  visit(i-1,j,cur+1);
        if(i>=0&&i<N&&j+1>=0&&j+1<M&&vis[i][j+1]==0)  visit(i,j+1,cur+1);
        if(i>=0&&i<N&&j-1>=0&&j-1<M&&vis[i][j-1]==0)  visit(i,j-1,cur+1);
        vis[i][j]=0;//千万记得消除标记，这步要读者深思
    }
}

int main()
{
    while(cin>>N>>M>>T){
        if(N==0&&M==0&&T==0)
            break;

        ok=0;//记得初始化
        for(int i=0;i<=N-1;i++){
         cin>>mat[i];   //输入图
        }

    memset(vis,0,sizeof(vis));//初始化，将vis【】【】数组全部赋值为0；
    int a,b;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(mat[i][j]=='S')
            a=i,b=j;//记录S的坐标
        }
    }
  
    visit(a,b,0);//从S开始访问
    if(ok==0)
        cout<<"NO"<<endl;
    else if(ok==1)
        cout<<"YES"<<endl;
}
    return 0;
}
/*#include<iostream>
#include<cstdio>
using namespace std;
char **map;
int n,m,t,di,dj;
bool dfs(int time,int i,int j){
	if(0==time){
		if(i==di&&j==dj) 
			return true;
	}
	if(time<0||abs(i-di)+abs(j-dj)>time) return false;
    char mark=map[i][j];
	map[i][j]='X';
	if(i>0&&map[i-1][j]!='X'&&dfs(time-1,i-1,j))
		return true;
	if(i<n-1&&map[i+1][j]!='X'&&dfs(time-1,i+1,j))
		return true;
	if(j>0&&map[i][j-1]!='X'&&dfs(time-1,i,j-1))
		return true;
	if(j<m-1&&map[i][j+1]!='X'&&dfs(time-1,i,j+1))
		return true;
	map[i][j]=mark;
	return false;
}
int main(char argc,char *argv[])
{
	int i,j;
	int si,sj;
	while(scanf("%d %d %d",&n,&m,&t)!=EOF&&(n||m||t)){
		getchar();
		map=new char*[n];
		for(i=0;i<n;i++)
			map[i]=new char[m];
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				scanf("%c",&map[i][j]);
				if(map[i][j]=='S'){
					si=i;sj=j;
				}
				if(map[i][j]=='D'){
					di=i;dj=j;
				}
			}
			getchar();
		}
		if(!((abs(si-di)+abs(sj-dj)-t)&1)&&dfs(t,si,sj))
			printf("YES\n");
		else printf("NO\n");
		delete []map;
	}
	return 0;
}*/