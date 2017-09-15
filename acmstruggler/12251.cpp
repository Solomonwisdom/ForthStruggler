////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-18 08:25:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1225
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1712KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct teams{
	string name;
	int score,goal,win;
	teams():score(0),goal(0),win(0){}
};
bool compare(teams s,teams t)
{
	if(s.score>t.score) return true;
	else if(s.score<t.score) return false;
	else{
		if(s.win>t.win) return true;
		else if(s.win<t.win) return false;
		else{
			if(s.goal>t.goal)return true;
			else if(s.goal<t.goal)return false;
			else return s.name<t.name;
		}
	}
}
int main(void){
	teams *team;
	string s1,s2,temp;
	int n,p1,p2,i,k,j;
	char c;
	while(scanf("%d",&n)!=EOF){
		k=0;
		team=new teams[n];
		for(i=0;i<n*(n-1);i++){
			cin>>s1>>temp>>s2>>p1>>c>>p2;
			for(j=0;j<k;j++)
				if(team[j].name==s1){
					team[j].win+=p1-p2;
					team[j].goal+=p1;
				    if(p1>p2)team[j].score+=3;
				    else if(p1==p2) team[j].score++;
					break;
				 }
			if(j==k){
				team[j].name=s1;
				team[j].win+=p1-p2;
				team[j].goal+=p1;
				if(p1>p2)team[j].score+=3;
				else if(p1==p2)  team[j].score++;
				k++;
			}
			for(j=0;j<k;j++)
				if(team[j].name==s2){
					team[j].win+=p2-p1;
					team[j].goal+=p2;
				    if(p1==p2)team[j].score++;
				    else if(p1<p2) team[j].score+=3;
				    break;}
			if(j==k){
				team[k].name=s2;
				team[j].win+=p2-p1;
				team[j].goal+=p2;
				if(p1==p2)team[j].score++;
				else if(p1<p2) team[j].score+=3;
				k++;
			}
		}
		sort(team,team+n,compare);
		for(i=0;i<n;i++)
			cout<<team[i].name<<' '<<team[i].score<<endl;
		cout<<endl;
		delete []team;
	}
	return 0;
}