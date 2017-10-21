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
����ͨ���εο�Ĵ򳵺ܷ��㣬������Ҳϣ���������ҵ��ҵ����Ӷ˽�ҳ�����Ϊ�û������ṩ���㡣���粻ͬ��˽�ҳ���������Ը���ṩ�쳵�����ʱ��Σ����Ҳ�ͬ˽�ҳ�����ӶӶ��ͬ����[L,R]�����ʾ˽�ҳ���ÿ��Ը���ṩ�쳵�����ʱ��Σ�C��ʾ��Ҫ��Ӷ��
���ܷ��Ч���ţ����ݸ���˽�ҳ�����ʱ���Ӷ��Ҫ�󣬱�֤��ÿ���[0,T]ʱ���Ϊ�û������ṩ���㣬���������ٵ�Ӷ��

Input

�ж��������������һ��Ϊ������M(0<=M<=20)��ÿ����������һ����N��1<=N<=100000����ʾԸ������˽�ҳ�����������T(1<=T<=1000000000)��ʾ��Ҫ���ǵ�ʱ��ε����ֵ�����N��ΪL R C������0<=L<R<=T, 1<=C<=1000��

Output

��Ӧÿ�����������������ʱ��γ��е���СӶ���������˽�ҳ�����ʱ��β����ܸ���[0,T]ʱ������-1��

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