////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-26 08:00:53
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1265
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1620KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main(void)
{
	int n;
	float f;
	double d;
	unsigned char *p;
	scanf("%d",&n);
	while(n--){
		scanf("%f",&f);
		d=(double)f;
		f=(float)d;
		p=(unsigned char*)&f;
		printf("%.2X%.2X%.2X%.2X\n",p[3],p[2],p[1],p[0]);
	}
	return 0;
}
