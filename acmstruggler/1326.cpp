////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-20 09:05:22
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1326
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1628KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main(void){
	int n,*hi,average,move,count=0;
	while(scanf("%d",&n)){
		if(n==0) break;
		count++;
		hi=new int[n];
		average=0;
		for(int i=0;i<n;i++){
			scanf("%d",&hi[i]);
			average+=hi[i];
			if(i==n-1) average/=n;
		}
		move=0;
		for(int i=0;i<n;i++)
			if(hi[i]>average)
				move+=hi[i]-average;
		printf("Set #%d\nThe minimum number of moves is %d.\n\n",count,move);
		delete []hi;
	}
	return 0;
}