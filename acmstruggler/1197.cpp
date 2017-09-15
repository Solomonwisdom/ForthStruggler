////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-17 17:15:07
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1197
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1612KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	int sum1,sum2,sum3;
	char dec[5]={""},duo[5]={""},hex[5]={""};
	for(int i=2992;i<10000;i++){
		itoa(i,dec,10);
		sum1=sum2=sum3=0;
		for(int j=0;dec[j]!='\0';j++)
			sum1+=(dec[j]-'0');
		itoa(i,duo,12);
		for(int j=0;duo[j]!='\0';j++)
		{
			if(duo[j]>='a'&&duo[j]<='c') sum2+=(duo[j]-'a'+10);
			else sum2+=(duo[j]-'0');
		}
		itoa(i,hex,16);
		for(int j=0;hex[j]!='\0';j++)
		{
			if(hex[j]>='a'&&hex[j]<='f') sum3+=(hex[j]-'a'+10);
			else sum3+=(hex[j]-'0');
		}
		if(sum1==sum2&&sum1==sum3) printf("%d\n",i);
	}
	return 0;
}