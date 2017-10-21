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

���ȵ�TT�ʹ����һ������ʯ��ͻȻ������Щ��ʯ�����ˡ������Һ����ǵ�ÿ����ʯ�ļ�ֵ�����һ����������ʣ����ʯ���ܼ�ֵ�����ڣ�����֪��������Щ��ʯ�����ˣ���ҿ����������

Input
   ��һ��Ϊһ������M,��ʾ�м������������
   �ڶ���һ������TotalW����ʾʣ�µ���ʯ���ܼ�ֵ��
   ������һ������N��1<N<=100������ʾ���ж�����ʯ��
   ������N�У�ÿ��һ������Wi��1<=Wi<=1000������ʾÿ����ʯ�ļ�ֵ��

Output

    ����޽⣬�������0��������ж�⣬�������-1�������򣬰������������������ʯ�ı�ţ���ž����������ʯ��˳�򣩣�����������֮����һ���ո���������һ���������޿ո�

   ÿ����Ҫ���С�

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