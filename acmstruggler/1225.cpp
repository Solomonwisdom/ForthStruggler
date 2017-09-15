////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-18 07:57:45
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1225
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1700KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;
struct team
{
	int jifen,goal,net;
	string name;
};
void search(string kkkk,int &nnnn,team TE[100],int add,int jian,int jifenjia); 
bool  cmp(team a1,team a2)
{
	if(a1.jifen>a2.jifen)
	{return 1;}
	else if(a1.jifen<a2.jifen)
	{return 0;}
	else
	{
		if(a1.net>a2.net)
		{return 1;}
		else if(a1.net<a2.net)
		{return 0;}
		else
		{
			if(a1.goal>a2.goal)
			{return 1;}
			else if(a1.goal<a2.goal)
			{return 0;}
			else
			{
				if(a1.name<=a2.name)
				{return 1;}
				else if(a1.name>a2.name)
				{return 0;}
			}
		}
	}
}
int main()
{
	int a;
	while(cin>>a)
	{
		team TEAM[100];
		for(int i=0;i<a;i++)
		{
			TEAM[i].jifen=0;
			TEAM[i].goal=0;
			TEAM[i].net=0;
		}
		int j=0;
		for(int i=0;i<a*(a-1);i++)
		{
			string n1,n2,vs,fen;
			int p1,p2;
			cin>>n1>>vs>>n2>>fen;		
			p1=fen[0]-'0';p2=fen[2]-'0';
			int jia1,jia2;
			if(p1>p2)
			{jia1=3;jia2=0;}
			else if(p1==p2)
			{jia1=1;jia2=1;}
			else
			{jia1=0;jia2=3;}
			search(n1,j,TEAM,p1,p2,jia1);search(n2,j,TEAM,p2,p1,jia2);
		}
		sort(TEAM,TEAM+a,cmp);
		for(int i=0;i<a;i++)
		{
			cout<<TEAM[i].name<<" "<<TEAM[i].jifen<<endl;
		}
		cout<<endl;
	}
	return 0;
}
void search(string kkkk,int &nnnn,team TE[100],int add,int jian,int jifenjia)
{
	for(int i=0;i<nnnn;i++)
	{
		if(TE[i].name==kkkk)
		{
			TE[i].goal+=add;
			TE[i].net+=add;
			TE[i].net-=jian;
			TE[i].jifen+=jifenjia;
			return;
		}
	}
	TE[nnnn].goal+=add;
	TE[nnnn].net+=add;
	TE[nnnn].net-=jian;
	TE[nnnn].jifen+=jifenjia;
	TE[nnnn].name=kkkk;
	nnnn++;
}