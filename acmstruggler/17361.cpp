////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-21 19:31:53
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1736
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1628KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string temp;
	int n=0,count,len;
	char s[1000];
	while(gets(s)!=NULL){
		count=0;
		len=strlen(s);
		for(int j=0;j<len;j++){
			temp="";
			if(j+1<len) temp=temp+s[j]+s[j+1];
			if(temp=="¡°"||temp=="¡±") count++;
			if(s[j]==',') printf("£¬");
			else if(s[j]=='.')printf("¡£");
			else if(s[j]=='!') printf("£¡");
			else if(s[j]=='?') printf("£¿");
			else if(s[j]=='"'){
				if(count%2==0) printf("¡°");
				else printf("¡±");
				count++;
			}
			else if(s[j]=='<'&&s[j+1]=='<'){
				printf("¡¶");
				j++;
			}
			else if(s[j]=='>'&&s[j+1]=='>'){
				printf("¡·");
				j++;
			}
			else printf("%c",s[j]);
		}
		printf("\n");
	}
	return 0;
}