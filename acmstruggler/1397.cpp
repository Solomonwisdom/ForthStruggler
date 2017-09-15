////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-20 17:17:41
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1397
////Problem Title: 
////Run result: Accept
////Run time:468MS
////Run memory:1944KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int prime[65537]={0};
int main(void){
	for(int i=2;i<50000;i++)
		if(!prime[i])
			for(int j=i+i;j<=65536;j+=i)
				prime[j]=1;
	int n,a,count;
	while(cin>>n&&n){
		count=0;
		for(a=2;a<=n/2;a++)
			if(!prime[a]&&!prime[n-a])count++;
		printf("%d\n",count);
	}
	return 0;
}