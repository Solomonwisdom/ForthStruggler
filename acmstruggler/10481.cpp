////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-15 18:03:34
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1048
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1668KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
int main(void)
{
	string ciphter;
	int len;
	while(true){
		getline(cin,ciphter);
		if(ciphter=="ENDOFINPUT") break;
		if(ciphter=="START") continue;
		if(ciphter=="END") continue;
		for(int i=0;i<ciphter.size();i++)
		{
			if(int(ciphter[i])>=65&&int(ciphter[i])<=90){
				ciphter[i]-=5;
			    if(int(ciphter[i]<65)) ciphter[i]+=26;
			}
		}
		cout<<ciphter<<endl;
	}
	return 0;
}