////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-17 14:43:02
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1148
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1684KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
using namespace std;
int main(void){
	int n,k,p1,p2;
	string s1,s2;
	int *win,*lose,i;
	bool en=false;
	while(cin>>n&&n)
	{
		if(en) cout<<endl;
		win=new int[n+1];
		lose=new int[n+1];
		for(i=1;i<=n;i++){ win[i]=0;lose[i]=0;}
		cin>>k;
		while(k--){
			cin>>p1>>s1>>p2>>s2;
			if((s1=="rock"&&s2=="scissors")||(s1=="scissors"&&s2=="paper")||
				(s1=="paper"&&s2=="rock"))
			{ win[p1]++;lose[p2]++;}
			if((s2=="rock"&&s1=="scissors")||(s2=="scissors"&&s1=="paper")||
				(s2=="paper"&&s1=="rock"))
			{ win[p2]++;lose[p1]++;}
		}
		for(i=1;i<=n;i++) if(win[i]==0&&lose[i]==0) cout<<"-"<<endl;
			else
				printf("%.3lf\n",double(win[i])/(win[i]+lose[i]));
		delete []win;
		delete []lose;
		en=true;
	}
	return 0;
}