////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-17 11:02:39
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1129
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1680KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string.h>
using namespace std;
char al[28]={'_','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','.'};
int main(void)
{
	char ct[71];
	int pc[71];
	int k,len,n;
	while(cin>>k&&k>0&&k<=300)
	{
		cin>>ct;
		len=strlen(ct);
		for(int i=0;i<len;i++)
		{
			if(ct[i]>='a'&&ct[i]<='z')
				pc[(k*i)%len]=(ct[i]-96+i)%28;
			else if(ct[i]=='_')
				pc[(k*i)%len]=i%28;
			else pc[(k*i)%len]=(27+i)%28;
		}
		for(int i=0;i<len;i++)
			cout<<al[pc[i]];
		cout<<endl;
	}
	return 0;
}