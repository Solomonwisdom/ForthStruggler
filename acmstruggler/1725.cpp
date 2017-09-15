////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-21 18:45:21
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1725
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1684KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cmath>
using namespace std;
int fac[32];
int main(void)
{
	int n,m,i;
	cin>>n;
	while(n--){
		scanf("%d",&m);
		fac[0]=1;
		for(i=1;;i++){
			fac[i]=fac[i-1]*i;
			if(fac[i]>m) break;
		}
		i--;
		int sum=0;
		for(;i>=1;i--){
			sum+=m/fac[i];
			m%=fac[i];
			if(m==0) break;
		}
		printf("%d\n",sum);
	}
	return 0;
}