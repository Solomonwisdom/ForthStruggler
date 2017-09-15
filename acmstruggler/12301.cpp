////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-18 10:50:07
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1230
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1620KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include<queue>
#include<map>
using namespace std;
#define lson ((root<<1)+1)
#define rson ((root<<1)+2)
#define MID ((l+r)>>1)
typedef long long ll;
typedef pair<int,int> P;
const int maxn=150;
const int base=1000;
const int inf=999999;
int isp[maxn];
int p[maxn];
void mark()//筛选素数
{
    int i,j;
    int len=0;
    isp[0]=isp[1]=1;
    for(i=2;i<maxn;i++)
        if(isp[i]==0)
    {
        p[len++]=i;
        for(j=i+i;j<maxn;j+=i)
        isp[j]=1;
    }
}
int main()
{
    int n,m,i,j,k,t;
    mark();
    int a[maxn],b[maxn];
    int lena,lenb;
    int x,y;
    char op;
    while(1)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        scanf("%d",&x);
        i=0;
        a[i++]=x;
        scanf("%c",&op);
        while(op==',')
        {
            scanf("%d",&x);
            a[i++]=x;
            scanf("%c",&op);
        }
        lena=i;

        scanf("%d",&x);
        i=0;
        b[i++]=x;
        scanf("%c",&op);
        while(op==',')
        {
            scanf("%d",&x);
            b[i++]=x;
            scanf("%c",&op);
        }
        lenb=i;
        reverse(a,a+lena);
        reverse(b,b+lenb);
        if(a[0]==0&&b[0]==0&&lena==1&&lenb==1)break;
        int maxlen=max(lena,lenb);
        int sum[maxn];
        memset(sum,0,sizeof(sum));
        for(i=0,k=0;i<maxlen;i++)//直接累加
        {
            sum[k++]=a[i]+b[i];
        }
        int lensum=k;
//        for(i=0;i<k;i++)
//            printf("(%d) ",sum[i]);
        for(i=0;i<lensum+10;i++)
        {
            int cur=sum[i]%p[i];//进位处理
            int mod=sum[i]/p[i];
            sum[i]=cur;
            sum[i+1]+=mod;
        }
        for(i=maxn-1;i>=0;i--)if(sum[i]!=0)break;//逆序输出
        j=i;
        printf("%d",sum[j]);
        for(i=j-1;i>=0;i--)
            printf(",%d",sum[i]);
        printf("\n");

    }

    return 0;
}
/*
#include<iostream>
#include<algorithm>
using namespace std;
int prime[27]={1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
int main(void){
	int a[26]={0},b[26]={0},sum[40]={0},i,ia,ib,j;
	char ch;
	while(true){
		ia=ib=1;
		scanf("%d",&a[ia]);
		scanf("%c",&ch);
		while(ch==',')
		{
			ia++;
			scanf("%d",&a[ia]);
			scanf("%c",&ch);
		}
		scanf("%d",&b[ib]);
		if(!a[1]&&!b[1]) break;
		scanf("%c",&ch);
		while(ch==',')
		{
			ib++;
			scanf("%d",&b[ib]);
			scanf("%c",&ch);
		}
		reverse(a+1,a+ia+1);
		reverse(b+1,b+ib+1);
		ia=ia>ib?ia:ib;
		j=0;
		for(i=1;i<=ia+5;i++)
			if(a[i]+b[i]+j<prime[i]){
				sum[i]=a[i]+b[i]+j;
				j=0;}
			else {
				sum[i]=(a[i]+b[i]+j)%prime[i];
				j=(a[i]+b[i]+j)/prime[i];
			}
		j=30;
		while(sum[j]==0) j--;
		for(;j>0;j--){
			if(j!=1) printf("%d,",sum[j]);
			else printf("%d\n",sum[j]);
		}
	}
	return 0;
}*/