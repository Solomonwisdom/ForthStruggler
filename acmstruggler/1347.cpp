////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-20 14:27:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1347
////Problem Title: 
////Run result: Accept
////Run time:280MS
////Run memory:1924KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<map>
using namespace std;
int main(void){
	int n,m,t,max;
	map<int,int> player;
	while(cin>>n>>m&&(m||n)){
		player.clear();
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				scanf("%d",&t);
				if(player.find(t)==player.end()) player[t]=1;
				else player[t]++;
			}
		max=0;
		for(map<int,int>::iterator iter=player.begin();iter!=player.end();iter++)
			max=(max>(iter->second))?max:iter->second;
		for(map<int,int>::iterator iter=player.begin();iter!=player.end();iter++)
			if(iter->second==max) iter->second=-1;
		max=0;
		for(map<int,int>::iterator iter=player.begin();iter!=player.end();iter++)
			max=(max>(iter->second))?max:iter->second;
		bool flag=false;
		for(map<int,int>::iterator iter=player.begin();iter!=player.end();iter++)
			if(iter->second==max){
				if(!flag){ printf("%d",iter->first);flag=true;}
				else printf(" %d",iter->first);
			}
		printf("\n");
	}
	return 0;
}