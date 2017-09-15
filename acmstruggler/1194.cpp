////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-17 16:18:38
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1194
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1684KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int n,a,b,i,c;
	cin>>n;
	while(n--){
		cin>>a>>b;
		i=(a-b)%2;
		c=(a-b)/2;
		if(i==0&&a>=b&&b>=0) cout<<c+b<<' '<<c<<endl;
		else cout<<"impossible"<<endl;
	}
	return 0;
}