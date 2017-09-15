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

int vis[10][10];//������¼������Ƿ񱻷��ʹ�
char mat[10][10];//������¼�����
int ok,T,M,N;//�����ok��������¼�жϵģ��������ȷ���ǿ����ӳ����壬ok�����Ϊ1

void visit(int i,int j,int cur)//��i��j��Ϊ��ǰ���ʵ����꣬curָ���ʵ㣨i��j���ǵ�cur�����տ�ʼcurΪ0
{
    if(cur>T||ok==1) return;//�������������T��������ȻҪ�˳������������֮ǰ�ķ���ȷ�������ӳ����壬������ȻҪ�˳�����
    else if(cur==T)  {//�����ǰ����ΪT����ôҪ�жϵ�ǰ�Ƿ����ſ�
        if(mat[i][j]=='D')//�ǵĻ�����ok=1
            ok=1;
        return;
    }
    else if(mat[i][j]=='.'||mat[i][j]=='S'){  //�����ǰ���ʵĸ��ӺϷ�����Ҫ©�ˡ�S������Ȼ��һ�εķ��ʽ�ʧЧ��
        vis[i][j]=1;  //���ϱ��
        if(i+1>=0&&i+1<N&&j>=0&&j<M&&vis[i+1][j]==0)  visit(i+1,j,cur+1);  //�ж���һ�������Ƿ��ڶ����������Ƿ񱻱�ǹ����ǣ�����
        if(i-1>=0&&i-1<N&&j>=0&&j<M&&vis[i-1][j]==0)  visit(i-1,j,cur+1);
        if(i>=0&&i<N&&j+1>=0&&j+1<M&&vis[i][j+1]==0)  visit(i,j+1,cur+1);
        if(i>=0&&i<N&&j-1>=0&&j-1<M&&vis[i][j-1]==0)  visit(i,j-1,cur+1);
        vis[i][j]=0;//ǧ��ǵ�������ǣ��ⲽҪ������˼
    }
}

int main()
{
    while(cin>>N>>M>>T){
        if(N==0&&M==0&&T==0)
            break;

        ok=0;//�ǵó�ʼ��
        for(int i=0;i<=N-1;i++){
         cin>>mat[i];   //����ͼ
        }

    memset(vis,0,sizeof(vis));//��ʼ������vis������������ȫ����ֵΪ0��
    int a,b;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(mat[i][j]=='S')
            a=i,b=j;//��¼S������
        }
    }
  
    visit(a,b,0);//��S��ʼ����
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