////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-09-07 18:03:12
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1023
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:1744KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#define N 60
using namespace std;
int main(void){
	int h[101][N+1],i,j,k,l,n;
	memset(h,0,sizeof(h));
	h[0][1]=1;
	h[1][1]=1;
	for(i=2;i<101;i++){
		for(j=0;j<i;j++)
			for(k=1;k<N;k++)
				for(l=1;l<N;l++)
					h[i][k+l-1]+=h[j][k]*h[i-j-1][l];
		for(j=1;j<N;j++)
		{
			h[i][j+1]+=h[i][j]/10;
			h[i][j]%=10;
		}

	}
	while(scanf("%d",&n)!=EOF){
		i=N;
		while(h[n][--i]==0);
		for(j=i;j>0;j--)
			printf("%d",h[n][j]);
		printf("\n");
	}
	return 0;
}