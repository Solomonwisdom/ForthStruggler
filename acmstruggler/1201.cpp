////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-17 19:12:09
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1201
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1676KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string.h>
using namespace std;
int main(void){
	int t,year,m,day,sum,x;
	cin>>t;
	for(int i=0;i<t;i++){
		sum=0;
		scanf("%d-%d-%d",&year,&m,&day);
		if(m==2&&day==29){ printf("-1\n");continue;}
		if(((year%4==0&&year%100!=0)||year%400==0)&&m<3) sum++;
		x=year+18;
		if(((x%4==0&&x%100!=0)||x%400==0)&&m>=3) sum++;
		for(int j=year+1;j<year+18;j++)
			if((j%4==0&&j%100!=0)||j%400==0) sum++;
		printf("%d\n",365*18+sum);
	}
	return 0;
}