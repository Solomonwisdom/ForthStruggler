////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-23 18:59:11
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1034
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1612KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
bool cmp(int a[],int n){
	for(int i=0;i<n-1;i++)
		if(a[i]!=a[i+1]) return false;
	return true;
}
int main(void)
{
    int n,*candy,i,round,*temp;
	while(scanf("%d",&n)!=EOF&&n){
		candy=new int[n];
		for(i=0;i<n;i++)
			scanf("%d",&candy[i]);
		round=0;
		temp=new int[n];
		while(true){
			if(cmp(candy,n)) break;
			for(i=0;i<n;i++) temp[i]=candy[i];
			for(i=0;i<n;i++){
				candy[i]=candy[i]/2+temp[(n-1+i)%n]/2;
			}
			for(i=0;i<n;i++)
				if(candy[i]%2) candy[i]++;
			round++;
		}
		printf("%d %d\n",round,candy[0]);
		delete []candy;
	}
    return 0;
}