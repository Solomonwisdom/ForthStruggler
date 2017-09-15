////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-09-07 18:42:56
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1025
////Problem Title: 
////Run result: Accept
////Run time:280MS
////Run memory:9548KB
//////////////////System Comment End//////////////////
#include<stdio.h>  
#include<string.h>  
#include<algorithm>  
using namespace std;  
#define N 500005  
int n;  
int stack[N];  
struct node  
{  
    int p;  
    int r;  
}a[N];  
int dp[N];  
int cmp(node b,node c)  
{  
    return b.p<c.p;  
}  
void LIS()  
{  
    //dp[i]��ʾǰi�������м��ϵ�i�����ֺ��м��������ǵ����ģ���ǰi���������ж��ٸ��ȵ�i������С��+1  
    //int stack[N];  
    memset(stack,0,sizeof(stack));  
    int top=0;  
    stack[top]=-99999999;  
    for(int i=1; i<=n; i++)  
    {  
        //���a[i]>ջ����Ԫ�أ���ѹջ  
        if(a[i].r>stack[top])  
        {  
            stack[++top]=a[i].r;  
            dp[i]=top;  
        }  
        //���a[i]������ջ����Ԫ�أ�����ֲ��ҵ�һ����a[i]���Ԫ��  
        else  
        {  
            int l=1,r=top;  
            while(l<=r)  
            {  
                int mid=(l+r)>>1;  
                if(a[i].r>stack[mid])  
                {  
                    l=mid+1;  
                }  
                else  
                    r=mid-1;  
            }  
            //�滻a[i]  
            stack[l]=a[i].r;  
            dp[i]=l;  
        }  
    }  
}  
int main()  
{  
    int cas=0;  
    while(scanf("%d",&n)!=EOF)  
    {  
        cas++;  
        memset(a,0,sizeof(a));  
        memset(dp,0,sizeof(dp));  
        for(int i=1;i<=n;i++)  
        {  
            scanf("%d%d",&a[i].p,&a[i].r);  
        }  
        sort(a+1,a+n+1,cmp);  
        LIS();  
        int maxx=-999999;  
        for(int i=1;i<=n;i++)  
        {  
            if(dp[i]>maxx)  
            maxx=dp[i];  
        }  
        if(maxx==1)  
        {  
            printf("Case %d:\n",cas);  
            printf("My king, at most %d road can be built.\n\n",maxx);  
        }  
        else  
        {  
        printf("Case %d:\n",cas);  
        printf("My king, at most %d roads can be built.\n\n",maxx);  
       }  
    }  
    return 0;  
}  