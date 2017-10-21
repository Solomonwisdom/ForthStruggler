#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
 
int w[101],dp[100003];
bool isl[101];
 
int main(void){
    int m,n;
    bool sel;
    unsigned int left,sum=0;
    scanf("%d",&m);
    while(m--){
        sum=0;
        memset(isl,0,sizeof(isl));
        memset(dp,0,sizeof(dp));
        scanf("%d",&left);
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",w+i);
            sum+=w[i];
        }
        int t;
        if(left<sum-left){
            sel=false;
            t=left;
        }
        else{
            sel=true;
            t=sum-left;
        }
        for(int i=0;i<n;i++)
            for(int j=t;j>=w[i];j--)
                dp[j]=max(dp[j-w[i]]+w[i],dp[j]);
        if(dp[t]!=t){
            printf("0\n");
            continue;
        }
        int fsum=0;
        for(int i=0;i<n;i++){
            if(dp[t]-dp[t-w[i]]==w[i]){
                isl[i]=true;
                fsum+=w[i];
            }
        }
        if(fsum!=t) printf("-1\n");
        else{
            int blank=false;
            for(int i=0;i<n;i++){
                if(isl[i]==sel){
                    if(!blank){
                        printf("%d",i+1);
                        blank=true;
                    }
                    else printf(" %d",i+1);
                }
            }
            printf("\n");
        }
    }
    return 0;
}
/**************************************************************
    Problem: 1212
    User: 08143203
    Language: C++
    Result: Accepted
    Time:8 ms
    Memory:1664 kb
Description

萌萌的TT和大家在一起数钻石，突然发现有些钻石不见了。但是幸好他记得每颗钻石的价值，而且还马上算出了剩下钻石的总价值，现在，他想知道都有哪些钻石不见了，大家快来帮帮他。

Input
   第一行为一个整数M,表示有几组测试样例。
   第二行一个整数TotalW，表示剩下的钻石的总价值。
   第三行一个整数N（1<N<=100），表示共有多少钻石。
   接下来N行，每行一个整数Wi（1<=Wi<=1000），表示每颗钻石的价值。

Output

    如果无解，则输出“0”；如果有多解，则输出“-1”；否则，按照升序输出不见的钻石的编号（编号就是输入的钻石的顺序），相邻两个数之间用一个空格隔开，最后一个数后面无空格。

   每组解后要换行。

Sample Input
2
270
4
100
110
170
200
270
4
100
110
160
170
Sample Output
2 4
-1
****************************************************************/