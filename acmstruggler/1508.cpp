////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-21 10:19:06
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1508
////Problem Title: 
////Run result: Accept
////Run time:124MS
////Run memory:1904KB
//////////////////System Comment End//////////////////
#include <iostream>
#include<string>
using namespace std;
int compute(string s,int start,int end)
{
	if(end<start) return 1;
	if(end==start){
		if(s[start]=='0') return 0;
		else return 1;
	}
	int half=(start+end)/2;
	if(s[half]=='0'||s[half]>'2'||(s[half]=='2'&&s[half+1]>'6'))
		return compute(s,start,half)*compute(s,half+1,end);
	else return compute(s,start,half)*compute(s,half+1,end)+compute(s,start,half-1)*compute(s,half+2,end);
}
int main(void)
{
	string code;
	int count=1,t=0;
	while(cin>>code&&code!="0")
		printf("%d\n",compute(code,0,code.size()-1));
	return 0;
}