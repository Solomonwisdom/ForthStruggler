////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-21 21:02:57
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1047
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1608KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define N 205
int main()
{
	int n,lena,l,i,j,flag;
	char a[N];
	int a1[N]={0};
    int a2[N];
    scanf("%d",&n);
	while(n--)
	{
		flag=0;
		while(scanf("%s",a)!=EOF)
		{
			flag++;
			if(a[0]=='0')
			{
				break;
			}
			memset(a2,0,sizeof(a2));
			lena=strlen(a);
			for(i=lena-1,l=0;i>=0;i--)
				a2[l++]=a[i]-'0';
			for(i=0;i<N;i++)
			{
				a1[i]+=a2[i];
				if(a1[i]>=10)
				{
					a1[i]-=10;
					a1[i+1]++;
				}
			}
		}
		if(flag==1)
		{
			printf("0\n");
		}
		else
		{
			for(i=N-1;i>=0;i--)
				if(a1[i])
					break;
				for(j=i;j>=0;j--)
					printf("%d",a1[j]);
				printf("\n");
		}
		if(n!=0)
			printf("\n");
		memset(a1,0,sizeof(a1));
	}
	return 0;
}