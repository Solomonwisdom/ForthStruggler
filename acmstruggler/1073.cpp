////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-15 22:18:11
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1073
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1600KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXN 2000

void fun_in(char a[]);
void clean(char a[]);
int fun_out(char a[], char b[]);

int main()
{
	int Ncase;

	scanf("%d", &Ncase);

	while(Ncase--)
	{
		char s1[MAXN]={0}, s2[MAXN]={0};
		int n;

		fun_in(s1), fun_in(s2);
		n = fun_out(s1, s2);

		switch(n)
		{
			case 1:
				printf("Accepted\n"); break;
			case 2:
				printf("Presentation Error\n"); break;
			case 3:
				printf("Wrong Answer\n"); break;
		}
	}

	return 0;
}

void fun_in(char a[])
{
	char s[MAXN];

	while(scanf("%s", s), strcmp(s, "START"));

	while(gets(s), strcmp(s, "END"))
	{
		if(s[0] != '\0')
			strcat(a, s);
		else
			strcat(a, "\n");
	}
}

int fun_out(char a[], char b[])
{
	if(!strcmp(a, b))
		return 1;

	clean(a), clean(b);
	
	if(!strcmp(a, b))
		return 2;

	return 3;
}

void clean(char a[])
{
	char s[MAXN];
	int i, k=0;

	for(i=0; a[i]; i++)
	{
		if(a[i] == ' ' || a[i] == '\t' || a[i] == '\n')
			continue;
		s[k++] = a[i];
	}
	s[k++] = '\0';

	strcpy(a, s);
}
/*#include<iostream>
#include<string.h>
using namespace std;
void input(char a[])
{
	char s[5001];
	while(scanf("%s",s)&&strcmp(s,"START"));
	while(gets(s)&&strcmp(s,"END"))
	{
		if(s[0]!='\0') strcat(a,s);
		else strcat(a,"\n");
	}
}
void simplify(char a[])
{
	int k=0;
	char s[5001];
	for(int i=0;a[i];i++){
		if(a[i]==' '||a[i]=='\n'||a[i]=='\t')
			continue;
		else s[k++]=s[i];}
	s[k++]='\0';
	strcpy(a,s);
}
int kind(char a[],char b[])
{
	if(!strcmp(a,b)) return 0;
	simplify(a),simplify(b);
	if(!strcmp(a,b)) return 1;
	return 2;
}
int main(void)
{
	int T;
	char st[5001]={0};
	char us[5001]={0};
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		input(st),input(us);
		int n=kind(st,us);
		switch(n){
		case 0: cout<<"Accepted"<<endl;break;
		case 1: cout<<"Presentation Error"<<endl;break;
		case 2: cout<<"Wrong Answer"<<endl;break;
		}
	}
	return 0;
}*/