////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-22 15:19:24
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1161
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1656KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main(void)
{
    char str[1001];
	while(gets(str)!=NULL){
		for(int i=0;str[i]!='\0';i++)
			if(str[i]>='A'&&str[i]<='Z')
				str[i]+=32;
		cout<<str<<endl;
	}
    return 0;
}