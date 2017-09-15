////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-18 09:03:07
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1229
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1684KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
using namespace std;
int main(void){
	int a,b,k,l;
	while(cin>>a>>b>>k&&a&&b)
	{
		l=1;
		while(k--) l*=10;
		if(a%l==b%l) cout<<-1<<endl;
		else cout<<a+b<<endl;
	}
	return 0;
}