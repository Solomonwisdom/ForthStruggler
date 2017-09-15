////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-21 15:53:37
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1678
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:1732KB
//////////////////System Comment End//////////////////
#include <iostream>
#include<algorithm>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main(void)
{
	int t,n,*price,sumdis;
	int i;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		sumdis=0;
		price=new int[n];
		for(i=0;i<n;i++)
			scanf("%d",&price[i]);
		sort(price,price+n,cmp);
		for(int i=2;i<n;i+=3)
			sumdis+=price[i];
		printf("%d\n",sumdis);
		delete []price;
	}
	return 0;
}