#include <cstdio>
#include <cstring> 
#include <cmath>
#include <algorithm>
 
using namespace std;
 
long long f[202];
int main() {
    int T;
    scanf("%d",&T);
    while(T--){
        memset(f,0x7f,sizeof(f));
        f[0]=0;
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            for(int j=n;j>=1;j--){
                for(int k=j;k>0;k--){
                    long long temp;
                    if(f[j]>(temp=f[j-k]+a*pow(k,1.0*b)))
                        f[j]=temp;
                }
            }
        }
        printf("%lld\n",f[n]);
    } 
    return 0;
}
/**************************************************************
    Problem: 1232
    User: 08143203
    Language: C++
    Result: Accepted
    Time:112 ms
    Memory:820 kb
Description

TT要完成n篇论文，论文的内容可以从m个课题中选择。由于课题数有限，TT不得不重复选择一些课题。对于某个课题i，若TT计划一共写x篇论文，则完成该课题的论文总共需要花费Ai*x^Bi个单位时间（系数Ai和指数Bi均为正整数）。给定与每一个课题相对应的Ai和Bi的值，请帮助TT计算出如何选择论文的课题使得他可以花费最少的时间完成这n篇论文。

Input
一共T组测试用例
第一行有两个用空格隔开的正整数n和m，分别代表需要完成的论文数和可供选择的课题数。
以下m行每行有两个用空格隔开的正整数。其中，第i行的两个数分别代表与第i个课题相对应的时间系数Ai和指数Bi。
对于30%的数据，n<=10,m<=5；
对于100%的数据，n<=200，m<=20，Ai<=100，Bi<=5。

Output

每组数据输出完成n篇论文所需要耗费的最少时间。

Sample Input
1
10 3
2 1
1 2
2 1
Sample Output
19
****************************************************************/