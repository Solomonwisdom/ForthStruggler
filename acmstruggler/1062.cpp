////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-15 20:11:41
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1062
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1676KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string.h>
using namespace std;
int main(void)
{
	int T,i,len,j;
	cin>>T;
	getchar();
	char str[1001];
	while(T--)
	{
		gets(str);
		len=strlen(str);
		i=0;
		while(i<len)
		{
			if(i==len-1&&str[i]!=' '){
				j=i;
				while(str[j]!=' '&&j>=0)
					cout<<str[j--];
				break;
			}
			while(str[i]!=' ') {
				i++;
				if(i==len-1) break;
			}
			if(i==len-1&&str[i]!=' ') continue;
			j=i-1;
			while(str[j]!=' '&&j>=0)
					cout<<str[j--];
			while(str[i]==' ') {cout<<' ';i++;}
		}
		cout<<endl;
	}
	return 0;
}