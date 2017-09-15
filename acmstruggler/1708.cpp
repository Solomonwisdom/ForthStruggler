////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-21 16:29:39
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1708
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1616KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main(void)
{
	int sum[51][26];
	int n,k;
	char s1[31],s2[31];
	scanf("%d",&n);
	getchar();
	while(n--){
		scanf("%s %s %d",s1,s2,&k);
		memset(sum,0,sizeof(sum));
		for(int i=0;s1[i]!='\0';i++)
			sum[0][s1[i]-'a']++;
		for(int i=0;s2[i]!='\0';i++)
			sum[1][s2[i]-'a']++;
		for(int i=2;i<=k;i++)
			for(int j=0;j<26;j++)
				sum[i][j]=sum[i-2][j]+sum[i-1][j];
		for(int i=0;i<26;i++)
			printf("%c:%d\n",'a'+i,sum[k][i]);
		printf("\n");
	}
	return 0;
}