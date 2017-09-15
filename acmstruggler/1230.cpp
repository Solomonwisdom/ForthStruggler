////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-18 09:43:24
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1230
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1616KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<string.h>
#define For(i,n) for(i=1;i<=n;++i)
#define MAXN 100005
using namespace std;
int prime[26]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
void rev(int a[],int n)
{
    int i;
    for(i=1;i<=(n/2);++i)
    {
        int temp;
        temp=a[i];
        a[i]=a[n-i+1];
        a[n-i+1]=temp;
    }
}
int main()
{
    while(1)
    {
        int na,nb,a[26],b[26],ans[30],i,ia=1,ib=1,p=0,k=0;
        char ch;
        scanf("%d",&a[ia]);
        scanf("%c",&ch);
        while(ch==',')
        {
            ++ia;
            scanf("%d",&a[ia]);
            scanf("%c",&ch);
        }
        na=ia;
        scanf("%d",&b[ib]);
        scanf("%c",&ch);
        if(!a[1]&&!b[1]) break;
        while(ch==',')
        {
            ++ib;
            scanf("%d",&b[ib]);
            scanf("%c",&ch);
        }
        nb=ib;
        rev(a,na);rev(b,nb);
        int *aa=a,*bb=b;
        if(na<nb)
        {
            int temp=na;
            na=nb;
            nb=temp;
            aa=b;
            bb=a;
        }
        For(i,nb)
        {
            ans[i]=aa[i]+bb[i]+p;
            p=0;
            while(ans[i]>=prime[i])
            {
                ++p;
                ans[i]-=prime[i];
            }
        }
        for(i=nb+1;i<=na;++i)
        {
            ans[i]=aa[i]+p;
            p=0;
            while(ans[i]>=prime[i])
            {
                ++p;
                ans[i]-=prime[i];
            }
        }
        k=na;
        if(p) {ans[na+1]=p;++k;}
        rev(ans,k);
        printf("%d",ans[1]);
        for(i=2;i<=k;++i) printf(",%d",ans[i]);
        printf("\n");
    }
    return 0;
}