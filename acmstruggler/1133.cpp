////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-22 09:30:27
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1133
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1624KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main(void)
{
	int num[500];
	int m,n,p=1,i,j,sum,max;
	while(scanf("%d %d",&m,&n)!=EOF&&(m||n)){
		printf("Test #%d:\n",p++);
		if(n>m){
			printf("0\n");
			continue;
		}
		memset(num,0,sizeof(num));
		num[0]=max=1;
		for(i=2;i<=m+n;i++){
			sum=0;
			if(i!=m+1){
				for(j=0;j<max;j++){
					num[j]=num[j]*i+sum;
					sum=num[j]/10;
					num[j]%=10;
					if(sum&&j==max-1)
						max++;
				}
			}
		}
		if(n){
			for(j=0,sum=0;j<max;j++)
			{
				num[j]=num[j]*(m+1-n)+sum;
			    sum=num[j]/10;
			    num[j]%=10;
			    if(sum&&j==max-1)
					max++;
			}
		}
		for(i=max-1;i>=0;i--)
			printf("%d",num[i]);
		printf("\n");
	}
	return 0;
}