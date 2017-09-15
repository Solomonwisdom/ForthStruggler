////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-22 11:02:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1297
////Problem Title: 
////Run result: Accept
////Run time:577MS
////Run memory:1660KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main(void)
{
	int fib[5][2006];
	int n,i,j,k,jia,max;
	while(scanf("%d",&n)!=EOF){
		memset(fib,0,sizeof(fib));
		fib[0][0]=1;
		fib[1][0]=2;
		fib[2][0]=4;
		fib[3][0]=7;
		fib[4][0]=2;
		fib[4][1]=1;
		if(n==4){
			printf("7\n");
			continue;
		}
		if(n==1||n==2||n==3){
			printf("%d\n",fib[n-1][0]);
			continue;
		}
		max=2;
		for(i=5;i<n;i++){
			for(j=0;j<4;j++){
                for(k=0;k<max;k++)
                    fib[j][k]=fib[j+1][k];
            }
            jia=0;
            for(j=0;j<max;j++){
                fib[4][j]=fib[0][j]+fib[2][j]+fib[3][j]+jia;
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