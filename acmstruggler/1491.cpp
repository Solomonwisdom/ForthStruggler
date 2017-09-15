////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-21 09:42:10
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1491
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1680KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int monthdays[]={0,0,31,59,90,120,151,181,212,243,273};
int main(void)
{
	int mon,day,t;
	cin>>t;
	while(t--){
		cin>>mon>>day;
		if(mon==10&&day==21) {
			printf("It's today!!\n");
			continue;
		}
		if((mon==10&&day>21)||(mon>10)){
			printf("What a pity, it has passed!\n");
			continue;
		}
		printf("%d\n",294-monthdays[mon]-day);
	}
	return 0;
}