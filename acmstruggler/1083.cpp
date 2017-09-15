////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-24 13:23:35
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1083
////Problem Title: 
////Run result: Accept
////Run time:358MS
////Run memory:6652KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
bool **stu,*issel;
int p,n,*match;
bool find(int x){
	for(int i=0;i<n;i++){
		if(stu[x][i]&&!issel[i]){
			issel[i]=true;
			if(match[i]==-1||find(match[i])){
				match[i]=x;
				return true;
			}
		}
	}
	return false;
}
int main(void)
{
    int t;
	int count,s;
	int i,j,sum;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&p,&n);
		stu=new bool*[p];
		match=new int[n];
		issel=new bool[n];
		for(i=0;i<p;i++)
		{
			stu[i]=new bool[n];
			for(j=0;j<n;j++)
				stu[i][j]=false;
		}
		for(i=0;i<p;i++){
			scanf("%d",&count);
			while(count--)
			{
				scanf("%d",&s);
				stu[i][s-1]=true;
			}
		}
		sum=0;
		for(i=0;i<n;i++)
			match[i]=-1;
		for(i=0;i<p;i++)
		{
			for(j=0;j<n;j++) issel[j]=false;
			if(find(i)) sum++;
		}
		if(sum==p)
			printf("YES\n");
		else printf("NO\n");
		delete []issel;
		delete []match;
		delete []stu;
	}
    return 0;
}