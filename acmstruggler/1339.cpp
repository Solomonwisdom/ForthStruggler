////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-20 11:46:28
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1339
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1684KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
void calculate(int m){
	int count=0;
	while(m%2==0){
		m/=2;
		count++;
	}
	printf("%d %d\n",m,count);
}
int main(void){
	int n,m;
	cin>>n;
	while(n--){
		cin>>m;
		calculate(m);
	}
	return 0;
}