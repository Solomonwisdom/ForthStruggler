////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-18 12:39:28
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1235
////Problem Title: 
////Run result: Accept
////Run time:156MS
////Run memory:1688KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main(void){
	int n,*grade,p,count;
	while(cin>>n&&n){
		grade=new int[n];
		for(int i=0;i<n;i++)
			scanf("%d",&grade[i]);
		scanf("%d",&p);
		count=0;
		for(int i=0;i<n;i++) if(grade[i]==p) count++;
		printf("%d\n",count);
		delete []grade;
	}
	return 0;
}