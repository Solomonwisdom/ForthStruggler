////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-21 21:02:35
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1047
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1624KB
//////////////////System Comment End//////////////////
#include <iostream>
#include<algorithm>
using namespace std;
int main(void)
{
	char sum[101],a[101];
	int n,r,i,count;
	scanf("%d",&n);
	while(n--){
		count=0;
		memset(sum,'0',sizeof(sum));
		while(scanf("%s",a)!=EOF){
			count++;
			if(a[0]=='0') break;
			reverse(a,a+strlen(a));
			r=0;
			for(i=0;i<strlen(a);i++){
				if(sum[i]+a[i]-'0'>'9'){
					sum[i]+=a[i]-'0'-10;
					sum[i+1]++;
				}
				else sum[i]+=a[i]-'0';
			}
		    while(sum[i]>'9') {
				sum[i]-=10;
				sum[++i]++;
			}
		}
		if(count==1){
			printf("0\n");
		}
		else{
			for(i=100;sum[i]=='0';i--);
		    while(i>=0) printf("%c",sum[i--]);
			printf("\n");
		}
		if(n!=0) printf("\n");
	}
	return 0;
}