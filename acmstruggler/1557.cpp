////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-21 11:49:17
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1557
////Problem Title: 
////Run result: Accept
////Run time:390MS
////Run memory:1680KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main(void)
{
	int s,t,n,sum,*piao,*times;
	cin>>t;
	while(t--){
		cin>>n;
		sum=0;
		piao=new int[n];
		times=new int[n];
		for(int i=0;i<n;i++){
			scanf("%d",&piao[i]);
			sum+=piao[i];
			times[i]=0;
		}
		for(int i=0,j;i<(1<<n);i++){
			s=0;
			for(j=0;j<n;j++)
				if((i&(1<<j))!=0) s+=piao[j];
			if(s*2<=sum) continue;
			for(j=0;j<n;j++)
				if((i&(1<<j))!=0&&(2*(s-piao[j])<=sum)) times[j]++;
		}
		for(int i=0;i<n;i++) {
			if(i==0) printf("%d",times[i]);
			else printf(" %d",times[i]);
		}
		printf("\n");
		delete []piao;
		delete []times;
	}
	return 0;
}/*#include<iostream>
using namespace std;
int last[21];
int vist[21];
int a[10000];
int b[10000];
int main()
{
    int T,sum,i,j,t,k,N,ii;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        sum=0;
        for(i=0;i<N;i++)
        {
            scanf("%d",&last[i]);
            sum+=last[i];
        }
        memset(vist,0,sizeof(vist));
        for(ii=0;ii<N;ii++)
        {
            for(i=0;i<=sum;i++)
            {
                a[i]=0;
                b[i]=0;
            }
            a[0]=1;
            for(i=0;i<N;i++)
            {
                if(i==ii) continue;
                for(j=0;j<=sum;j++)
                {
                    if(a[j]==0)
                        continue;
                    for(k=0,t=0;k+j<=sum&&t<=1;t++,k+=last[i])
                    {
                        b[j+k]+=a[j];
                    }
                }
                for(j=0;j<=sum;j++)
                {
                    a[j]=b[j];
                    b[j]=0;
                }
            }
            for(j=0;j<=sum/2;j++)
            {
                if(j+last[ii]>sum/2)
                    vist[ii]+=a[j];
            }
        }
        printf("%d",vist[0]);
        for(i=1;i<N;i++)
            printf(" %d",vist[i]);
        printf("n");
    }
    return 0;
}*/