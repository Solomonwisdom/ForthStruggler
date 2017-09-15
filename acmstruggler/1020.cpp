////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-14 20:24:35
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1020
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1692KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string.h>
using namespace std;
int main(void)
{
	int N,n,len;
	cin>>N;
	char s,str[10002]={'0'};
	for(int i=0;i<N;i++)
	{
		cin>>str;
		len=strlen(str);
		s=*str;
		char *c=str;
		n=0;
		while(len--)
		{
			if(*c==s){ n++; c++;}
			else{
				if(n!=1)
					cout<<n;
				cout<<s;
				s=*c;
				n=1;
				c++;
			}
		}
		if(n!=1) cout<<n;
		cout<<s<<endl;
	}
	return 0;
}