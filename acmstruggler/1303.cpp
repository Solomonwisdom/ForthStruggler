////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-18 20:51:45
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1303
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1692KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main(void){
	int num[15],t,i,count;
	while(cin>>t&&t!=-1)
	{
		num[0]=t;
		i=1;
		count=0;
		while(cin>>t&&t)
			num[i++]=t;
		for(int j=0;j<i-1;j++)
			for(int k=j+1;k<i;k++)
				if((num[j]==num[k]*2)||(num[j]*2==num[k])) count++;
		printf("%d\n",count);
	}
	return 0;
}