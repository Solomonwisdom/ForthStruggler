////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-20 18:35:44
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1408
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1696KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main(void){
	int i,time;
	double d,vul;
	while(cin>>vul>>d){
		time=vul/d;
		if(vul/d>time) time++;
		i=1;
		while(vul>1e-8){
			vul-=i*d;
			i++;
		}
		printf("%d\n",time+i-2);
	}
	return 0;
}