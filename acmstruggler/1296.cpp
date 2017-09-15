////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-26 09:52:05
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1296
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1632KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;
int main(void)
{
	int x,poww,res,a,part;
	char exp[2000];
	bool flag,is;
	while(scanf("%d",&x)!=EOF){
		scanf("%s",exp);
		is=true;
		poww=a=res=0;
		part=1;
		for(int i=0;i<strlen(exp);i++){
			if(i==0){
				if(exp[i]=='-')
					flag=false;
				else if(exp[i]=='+')
					flag=true;
				else if(exp[i]=='X'){
					flag=true;
					if(exp[i+1]=='^')
					    is=false;
					else{ 
						part=x;
						res+=part;
						is=true;
					}
				}
				else{
					a=exp[i]-'0';
					flag=true;
					if(exp[i+1]=='+'||exp[i+1]=='-'||exp[i+1]=='\0')
						res+=a;
				}
			}
			else if(exp[i]=='+'){
				a=0;poww=0;
				is=true;flag=true;}
			else if(exp[i]=='-'){
				a=poww=0;
				flag=false;is=true;}
			else if(exp[i]>='0'&&exp[i]<='9'&&is){
				a=a*10+exp[i]-'0';
				if(exp[i+1]=='+'||exp[i+1]=='-'||exp[i+1]=='\0'){
					part=a;
					if(flag) res+=part;
					else res-=part;
				}
			}
			else if(exp[i]=='X')
				if(exp[i+1]=='^')
					is=false;
				else{
					if(a==0)
						part=x;
					else
						part=a*x;
					if(flag) res+=part;
					else res-=part;
				}
			else if(exp[i]>='0'&&exp[i]<='9'&&!is){
				poww=poww*10+exp[i]-'0';
				if(exp[i+1]=='+'||exp[i+1]=='-'||exp[i+1]=='\0'){
					if(a==0) part=pow(x*1.0,1.0*poww);
					else  part=a*pow(x*1.0,1.0*poww);
					if(flag) res+=part;
					else res-=part;
				}
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
