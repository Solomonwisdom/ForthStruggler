////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-17 15:19:47
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1163
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1692KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<algorithm>
using namespace std;
int main(void){
	int n,s;
	while(cin>>n&&n)
	{
		s=1;
		for(int i=1;i<=n;i++)
			s=s*n%9;
		if(s) cout<<s<<endl;
		else cout<<9<<endl;
	}
	return 0;
}