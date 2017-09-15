////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-17 12:42:28
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1141
////Problem Title: 
////Run result: Accept
////Run time:171MS
////Run memory:1692KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cmath>
using namespace std;
int main(void)
{
	int year,power,i;
	double k;
	while(cin>>year&&year)
	{
		k=0;
		year=year/10-194;
		power=1<<year;
		for(i=1;;i++){ 
			k+=log10(i*1.0)/log10(2.0);
			if(k>power) break;
		}
		cout<<i-1<<endl;
	}
	return 0;
}