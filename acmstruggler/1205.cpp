////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-17 19:54:10
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1205
////Problem Title: 
////Run result: Accept
////Run time:1404MS
////Run memory:5584KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main(void){
	int t,n,*m,max;
	long long sum;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		m=new int[n];
		sum=0;
		max=0;
		for(int i=0;i<n;i++)
		{
			cin>>m[i];
			sum+=m[i];
			max=m[i]>max?m[i]:max;
		}
		if(sum-max+1>=max) printf("Yes\n");
		else printf("No\n");
		delete []m;
	}
	return 0;
}