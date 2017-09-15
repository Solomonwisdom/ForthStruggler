////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-19 17:38:49
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1321
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1676KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int main(void)
{
	char s[72];
	int n;
	cin>>n;
	getchar();
	while(n--){
		gets(s);
		reverse(s,s+strlen(s));
		cout<<s<<endl;
	}
	return 0;
}