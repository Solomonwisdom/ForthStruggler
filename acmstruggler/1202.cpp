////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-17 19:43:30
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1202
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1680KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main(void){
	int n;
	double p,g,sump,sumg;
	while(cin>>n)
	{
		sump=sumg=0;
		while(n--)
		{
			cin>>p>>g;
			if(g!=-1){
				sump+=p;
				if(g==100) sumg+=4*p;
				else if(g>=60) sumg+=(int(g/10-5)*p);
			}
		}
		if(sumg==0) cout<<"-1"<<endl;
		else printf("%.2lf\n",sumg/sump);
	}
	return 0;
}