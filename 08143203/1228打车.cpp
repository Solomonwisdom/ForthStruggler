#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
 
using namespace std;
 
const int MAX=100005;
 
typedef unsigned int ull;
struct taxi
{
    ull l;
    ull r;
    ull c;
}drs[MAX];
 
bool cmp(taxi t1,taxi t2)
{
    if(t1.l!=t2.l) return t1.l<t2.l;
    else if(t1.r!=t1.r) return t1.r<t2.r;
    else return t1.c<t2.c;
}
 
ull kt[MAX];
ull ans[MAX];
int main() 
{
    ull m,n,i;
    ull t;
    scanf("%u",&m);
    while(m--)
    {
        scanf("%u %u",&n,&t);
        for(i=0;i<n;i++)
        {
            scanf("%u %u %u",&drs[i].l,&drs[i].r,&drs[i].c);
            kt[i]=drs[i].r;
        }
        sort(drs,drs+n,cmp);
        sort(kt,kt+n);
        bool com=false;
        ull ks=unique(kt,kt+n)-kt;
        ull record=0;
        memset(ans,0xfff,sizeof(ull)*(ks+1));
        int pan=ans[ks];
        ans[0]=0;
        if(drs[0].l!=0||kt[ks-1]!=t)
        {
            printf("-1\n");
            continue;
        }
        for(i=0;i<ks;i++)
        {
            ull temp=i==0?0:kt[i-1];
            if(drs[record].l>temp)  continue;
            while(record<n&&drs[record].l<=temp)
            {
                if(drs[record].r>=kt[i])
                {
                    for(ull j=i+1;j<ks+1&&drs[record].r>=kt[j-1];j++)
                    {
                        if(drs[record].c+ans[i]<ans[j])
                            ans[j]=drs[record].c+ans[i];
                    }
                }
                record++;
            }
        }
        if(ans[ks]!=pan) printf("%u\n",ans[ks]);
        else printf("-1\n");
    }
    return 0;
}
/**************************************************************
    Problem: 1228
    User: 08143203
    Language: C++
    Result: Accepted
    Time:8 ms
    Memory:3228 kb
Description
现在通过滴滴快的打车很方便，假如你也希望在这个行业创业，雇佣私家车主，为用户出行提供方便。假如不同的私家车主都有其愿意提供快车服务的时间段，并且不同私家车主雇佣佣金不同。用[L,R]区间表示私家车主每天愿意提供快车服务的时间段，C表示其要求佣金。
你能否高效安排，根据各个私家车主的时间和佣金要求，保证在每天的[0,T]时间段为用户出行提供方便，并付出最少的佣金。

Input

有多个测试用例，第一行为用例数M(0<=M<=20)，每组用例，第一行是N（1<=N<=100000）表示愿意参与的私家车主的人数和T(1<=T<=1000000000)表示你要覆盖的时间段的最大值，后边N行为L R C，期中0<=L<R<=T, 1<=C<=1000。

Output

对应每个测试用例输出满足时间段出行的最小佣金数，如果私家车主的时间段不可能覆盖[0,T]时间段输出-1。

Sample Input
2
3 5
0 3 10
2 5 12
4 5 3
2 5
0 3 10
4 5 3
Sample Output
22
-1
****************************************************************/