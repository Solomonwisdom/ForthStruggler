////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-15 13:29:43
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1038
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1692KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
const double pi=3.1415927;
int main(void)
{
	int r,num=1;
	float d,t;
	double distance,MPH;
	while(cin>>d>>r>>t&&r)
	{
		distance=pi*d*r/(12*5280);
		MPH=distance/t*3600;
		printf("Trip #%d: %.2lf %.2lf\n",num++,distance,MPH);
	}
	return 0;
}