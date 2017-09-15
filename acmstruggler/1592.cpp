////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-21 14:22:21
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1592
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1612KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main(void)
{
	int left[100];
	int n,t,s;
	left[0]=1;
	while(scanf("%d",&n)!=EOF){
		s=0;
		memset(left,0,sizeof(left));
		left[s]=1;
		for(int i=0;i<n;i++){
			t=0;
			for(int j=0;j<=s;j++){
				if(j==0)
					left[j]=left[j]*2+1;
				else left[j]=left[j]*2+t;
				t=left[j]/10000;
				left[j]=left[j]%10000;
			}
			if(t){
				s++;
				left[s]=t;
			}
		}
		printf("%d",left[s]);
		for(int i=s-1;i>=0;i--)
			printf("%04d",left[i]);
		printf("\n");
	}
	return 0;
}