////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-25 11:09:35
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1117
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1620KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
#include<set>
#include<math.h>
#include<string>
using namespace std;
typedef long long ll;
using namespace std;
#define INF 10000000
int a[54][2];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF && n)
	{
		memset(a,0,sizeof(a));
		if(n==1)
		{
			printf("Printing order for %d pages:\n", n);
			printf("Sheet 1, front: Blank, 1\n");
			continue;
		}
		int i,j,k = n/4;
		if(n%4!=0 ) k++;
		for(i=1;i<=2*k;i++)
			a[i][0] =i;
		for(i=2*k,j=i+1;i>=1;i--,j++)
		{
			if(j<=n)
				a[i][1]=j;
		}
		printf("Printing order for %d pages:\n",n);
		char s[2][10]={"front","back "};
		char *p;
		for(i=1;i<=2*k;i++)
		{
			if(a[i][0]==0 && a[i][0]==0 )continue;
			j=i/2;
			if( i&1 )
			{
				p=s[0];
				j++;
			}
			else 
				p=s[1];
			printf("Sheet %d, %s:",j,p);
			if( i&1 )
				swap(a[i][0],a[i][1]);
			for(int m=0;m<2;m++)
			{
				if(a[i][m] ) printf(" %d",a[i][m]);
				else printf(" Blank");
				if(!m) putchar(',');
			}
			printf("\n");
		}
	}

}/*
#include<iostream>
#include<stack>
using namespace std;
struct sheet{
	int front1,front2,back1,back2;
};
int main(void){
	int page,n,i,j;
	stack<sheet> news,fac;
	sheet p;
	while(scanf("%d",&page)!=EOF&&page){
		n=page/4;
		if(page%4) n++;
		for(i=1,j=1;i<2*n;i+=2){
			p.front2=i;
			if(i+1<page) p.back1=i+1;
			else p.back1=0;
			news.push(p);
		}
		while(!news.empty()){
			p=news.top();
			if(i<=page){
				p.back2=i;
				i++;
				if(i<=page){
					p.front1=i;
					i++;
				}
				else
					p.front1=0;	
			}
			else{
				p.back2=0;
				p.front1=0;
			}
			news.pop();
			fac.push(p);
		}
		printf("Printing order for %d pages:\n",page);
		int k=1;
		while(!fac.empty()){
			p=fac.top();
			printf("Sheet %d, front: ",k);
			if(p.front1==0) printf("Blank, ");
			else printf("%d, ",p.front1);
			printf("%d\n",p.front2);
			if(p.back1!=0||p.back2!=0){
				printf("Sheet %d, back : ",k);
				if(p.back1!=0) printf("%d, ",p.back1);
				else printf("Blank, ");
				if(p.back2!=0) printf("%d\n",p.back2);
				else printf("Blank\n");
			}
			fac.pop();
			k++;
		}
	}
	return 0;
}*/