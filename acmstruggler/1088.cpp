////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-24 20:19:39
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1088
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1672KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstring>
using namespace std;
int main(void){
	char a[80],b[10000];
	int len,used=0,i=0;
	while(scanf("%s",a)!=EOF){
		if(strcmp(a,"<br>")==0){
			b[i++]='\n';
			used=0;
			continue;
		}
		if(strcmp(a,"<hr>")==0){
			if(used!=0) 
				b[i++]='\n';
			for(int j=0;j<80;j++)
				b[i++]='-';
			b[i++]='\n';
			used=0;
			continue;
		}
		len=strlen(a);
		if(len+used>=80){
			b[i++]='\n';
			for(int j=0;j<len;j++)
				b[i++]=a[j];
			used=len;
		}
		else{
			if(used!=0)
				b[i++]=' ';
			for(int j=0;j<len;j++)
				b[i++]=a[j];
			used+=len+1;
		}
	}
	b[i]='\0';
	cout<<b<<endl;
	return 0;
}