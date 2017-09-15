////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-22 10:23:57
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1250
////Problem Title: 
////Run result: Accept
////Run time:296MS
////Run memory:1656KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main(void)
{
	int fib[5][2006];
	int n,i,j,k,jia,max;
	while(scanf("%d",&n)!=EOF){
		if(n==1||n==2||n==3||n==4){
			printf("1\n");
			continue;
		}
		memset(fib,0,sizeof(fib));
		for(i=0;i<4;i++)
			fib[i][0]=1;
		fib[4][0]=4;
		max=1;
		for(i=5;i<n;i++){
			for(j=0;j<4;j++){
				for(k=0;k<max;k++)
					fib[j][k]=fib[j+1][k];
			}
			jia=0;
			for(j=0;j<max;j++){
				fib[4][j]=fib[0][j]+fib[1][j]+fib[2][j]+fib[3][j]+jia;
				jia=fib[4][j]/10;
				fib[4][j]%=10;
				if(jia&&j==max-1)
					max++;
			}
		}
		for(i=max-1;i>=0;i--)
			printf("%d",fib[4][i]);
		printf("\n");
	}
	return 0;
}