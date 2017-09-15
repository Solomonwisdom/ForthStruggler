////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-17 16:37:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1196
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1692KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,m,k;
	while(cin>>n&&n){
		m=n-(n&(n-1));
		cout<<m<<endl;
	}
	return 0;
}