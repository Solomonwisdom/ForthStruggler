////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-20 13:46:19
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1346
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1684KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cmath>
using namespace std;
bool dfs(int left,int num,int count)
{
	if(count==0) return left%num==0;
	if(left%num!=1) return false;
	return dfs(left-1-left/num,num,count-1);
}
int main(void){
	int sum,div[100],n,i;
	while(cin>>sum){
		if(sum<0) break;
		for(i=sum;i>=2;i--)
			if(dfs(sum,i,i)) break;
		if(i>=2)printf("%d coconuts, %d people and 1 monkey\n",sum,i);
		else printf("%d coconuts, no solution\n",sum);
	}
		/*n=0;
		for(int j=2;j*j<=sum;j++){
			if(sum%j==1){
				div[n++]=j;
				div[n++]=sum/j;}
		}
		sort(div,div+n);
		for(i=n-1;i>=0;i--){
			if(dfs(sum,div[i],div[i])) break;
		}
		if(i<0)printf("%d coconuts, no solution\n",sum);
		else printf("%d coconuts, %d people and 1 monkey\n",sum,div[i]);
	}*/
	return 0;
}