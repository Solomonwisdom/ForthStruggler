////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-18 19:01:13
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1276
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1644KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdio.h>
using namespace std;
int p[5005];
int main()
{
    int m,n,t,k,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&m);
        for(i=1;i<=5001;i++)
        {
            p[i]=1;
        }
        n=m;
        while(n>3)
        {
            k=0;n=0;
            for(i=1;i<=m;i++)
            {
                if(p[i])
                {
                k=k+1;
                if(k%2==0)
                    p[i]=0;
                n=n+p[i];
                }
            }
            k=0;
            if(n<=3)
                break;
            else
                n=0;
            for(i=1;i<=m;i++)
            {
                if(p[i])
                {
                    k=k+1;
                    if(k%3==0)
                        p[i]=0;
                }
                n=n+p[i];
            }
        }
        for(i=1;i<=m;i++)
        {
            if(p[i])
            {
               if(i==1)
                   printf("%d",i);
               else
                   printf(" %d",i);
            }
        }
       printf("\n");
    }
    return 0;
}
/*#include<iostream>
using namespace std;
int main(void){
	bool sr[5005]={true},flag;
	int n,peo,left,i,k;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&peo);
		left=peo;
		for(i=1;i<=peo;i++) sr[i]=true;
		while(left>3){
			for(i=1,k=0;i<=peo;i++)
				if(sr[i]){
					k++;
					if(k%2==0&&left>3){ sr[i]=false;left--;}
					if(left==3) break;
				}
			if(left<=3) break;
			for(i=1,k=0;i<=peo;i++)
				if(sr[i]){
					k++;
					if(k%3==0&&left>3){sr[i]=false;left--;}
					if(left==3) break;
				}
		}
		flag=false;
		for(i=1;i<=peo;i++)
			if(sr[i]) 
				if(flag) printf(" %d",i);
				else { printf("%d",i);flag=true;}
		printf("\n");
	}
	return 0;
}*/