////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-15 19:26:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1052
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1612KB
//////////////////System Comment End//////////////////
/*n匹马的n次比赛，这个过程过于复杂，为了简化过程，我们可以把这个过程分割成很多阶段*/ 
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int n,i,j;
    int tj[1100],tjwin;//田忌的马和他胜的局数 
    int king[1100],kingwin;//国王的马和他胜的局数 
    int tjfast,tjslow,kingslow,kingfast;//分别记录每个阶段田忌和国王的最快的马和最慢的马 
    while(scanf("%d",&n)&&(n!=0))
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&tj[i]);
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&king[i]);
        }
        sort(tj,tj+n);//按马匹速度升序排列 
        sort(king,king+n);
        tjwin=kingwin=0; 
        tjfast=kingfast=n-1;tjslow=kingslow=0;//记录最快最慢的马 
        /*每次让田忌该阶段最慢的马和国王最慢的马相比
        情况有三：
        一：田忌马比国王快，必赢,继续下匹马的比较  结果赢 
        二：田忌马比国王慢，和国王任意马都输，还不如消耗国王最快的马，让它与国王最快的马比赛 结果输 
        三：一样快，比较最快的马：
                   若田忌快马比国王的快，直接比赛 结果赢    
                   否则让慢马与国王快马比赛 思想还是消耗国王最快的马 结果输*/
         for(i=0;i<n;i++)
         {
             if(tj[tjslow]>king[kingslow])
             {
                 tjwin++;//田忌胜 
                 tjslow++;kingslow++;//进行下一阶段慢马比较 
             }
             else if(tj[tjslow]<king[kingslow])
             {
                 kingwin++;
                 tjslow++;kingfast--;//用最慢的马消耗了国王最快的马 
             }
             else
             {
                 if(tj[tjfast]>king[kingfast])
                 {
                     tjwin++;
                     tjfast--;kingfast--;//进行下一阶段慢马比较 
                 }
                 else 
                 {
                     if(tj[tjslow]<king[kingfast])//只有最慢的马慢于国王最快的马 国王才赢 第二组测试数据......无奈啊 
                     {
                          kingwin++;
                          tjslow++;kingfast--;//消耗国王最快的马 
                     }
                 } 
             } 
         }
         printf("%d\n",200*(tjwin-kingwin));
    }
    return 0;
}