////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-20 16:41:16
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1393
////Problem Title: 
////Run result: Accept
////Run time:187MS
////Run memory:1684KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main(void){
	int s,d,i,t;
	bool flag;
	while(cin>>s>>d&&s&&d){
		t=s;
		i=0;
		flag=true;
		while(t%60){
			t+=d*t%60;
			i++;
			if(i>10000){ flag=false;printf("Impossible\n");break;}
		}
		if(flag)printf("%d\n",i);
	}
	return 0;
}