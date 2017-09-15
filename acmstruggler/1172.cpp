////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-25 16:56:12
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1172
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:1608KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string.h>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

struct Student 
{
	int b,c,d;
}a[110];

int main()
{
	int n,i,j,sum,ji1,ji2,k,t,sji;
	char str1[5],str2[5];
	while(~scanf("%d",&n))
	{
		if(n==0)break;
		memset(a,0,sizeof(a));
		for(i=0;i<n;i++)
		{
			scanf("%d %d %d",&a[i].b,&a[i].c,&a[i].d);
		}
		sum=0;
		for(i=1000;i<10000;i++)
		{
			for(j=0;j<n;j++)
			{
				itoa(i,str1,10);
				itoa(a[j].b,str2,10);
				ji1=ji2=0;
				for(k=0;k<4;k++)
				{
					if(str1[k]==str2[k])
					{
						str1[k]=str2[k]=0;
						ji1++;
					}
				}
				if(ji1==a[j].d)
				{
					for(k=0;k<4;k++)
					{
						if(str1[k])
						{
							for(t=0;t<4;t++)
							{
								if(str1[k]==str2[t])
								{
									str1[k]=str2[t]=0;
									ji2++;
									break;
								}
							}
						}
					}
					if(ji2+ji1 != a[j].c)break;
				}
				else break;
			}
			if(j==n)
			{
				sum++;
				sji=i;
			}
		}
		if(sum>1)printf("Not sure\n");
		else printf("%d\n",sji);
	}
	return 0;
}