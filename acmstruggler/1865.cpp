////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-22 14:25:48
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1865
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:1696KB
//////////////////System Comment End//////////////////
#include <iostream>
#include<string>
using namespace std;
int main(void)
{
    int fib[3][1006];
	string list;
    int n,i,j,k,jia,max;
    int m;
    cin>>m;
    while(m--){
        cin>>list;
		n=list.size();
        memset(fib,0,sizeof(fib));
        fib[0][0]=1;
        fib[1][0]=2;
        fib[2][0]=3;
        if(n==1||n==2){
            printf("%d\n",fib[n-1][0]);
            continue;
        }
        max=1;
        for(i=3;i<n;i++){
            for(j=0;j<2;j++){
                for(k=0;k<max;k++)
                    fib[j][k]=fib[j+1][k];
            }
            jia=0;
            for(j=0;j<max;j++){
                fib[2][j]=fib[0][j]+fib[1][j]+jia;
                jia=fib[2][j]/10;
                fib[2][j]%=10;
                if(jia&&j==max-1)
                    max++;
            }
        }
        for(i=max-1;i>=0;i--)
            printf("%d",fib[2][i]);
        printf("\n");
    }
    return 0;
}