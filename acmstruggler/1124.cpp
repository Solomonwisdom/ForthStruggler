////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-17 09:47:42
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1124
////Problem Title: 
////Run result: Accept
////Run time:499MS
////Run memory:1684KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main(void)
{
	int t,n,i;
	cin>>t;
	while(t--){
		cin>>n;
		i=0;
		while(n/5>0){ n/=5;i+=n;}
		cout<<i<<endl;
	}
	return 0;
}