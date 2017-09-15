////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-23 19:50:58
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1035
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1620KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main(void)
{
    int x,y,i;
	int row,col;
	int **step;
	char **map;
	bool **visited;
	while(scanf("%d %d %d",&row,&col,&x)!=EOF&&row&&col&&x){
		getchar();
		y=1;
		map=new char*[row+1];
		visited=new bool*[row+1];
		step=new int*[row+1];
		map[0]=new char[col+1];
		visited[0]=new bool[col+1];
		step[0]=new int[col+1];
		for(i=1;i<=row;i++){
			map[i]=new char[col+1];
			visited[i]=new bool[col+1];
			step[i]=new int[col+1];
			for(int j=1;j<=col;j++){
				scanf("%c",&map[i][j]);
				visited[i][j]=false;
				step[i][j]=0;
			}
			getchar();
		}
		step[y][x]=1;
		while(true){
			int tx=x,ty=y;
			visited[y][x]=true;
			switch(map[y][x]){
			case'W': x--;break;
			case'S': y++;break;
			case'E': x++;break;
			case'N': y--;break;
			}
			if(x<1||x>col||y>row||y<1){
				printf("%d step(s) to exit\n",step[ty][tx]);
				break;
			}
			if(visited[y][x]){
				printf("%d step(s) before a loop of %d step(s)\n",step[y][x]-1,step[ty][tx]-step[y][x]+1);
				break;
			}
			step[y][x]=step[ty][tx]+1;
		}
		delete []step;
		delete []map;
		delete []visited;
	}
    return 0;
}