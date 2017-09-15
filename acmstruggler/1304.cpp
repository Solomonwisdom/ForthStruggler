////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-18 21:13:35
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1304
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1688KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
using namespace std;
int main(void){
	int n,mp,p,mpe,pe,sub,sumpe;
	string name,maxn;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>name;
		p=0;
		sumpe=0;
		for(int j=0;j<4;j++){
			cin>>sub>>pe;
			if(pe){
				pe+=20*(sub-1);
				sumpe+=pe;
				p++;
			}
		}
		if(!i){
			maxn=name;
			mp=p;
			mpe=sumpe;
		}
		else if(mp<p){
			maxn=name;
			mp=p;
			mpe=sumpe;
		}
		else if(mp==p&&sumpe<mpe){
			maxn=name;
			mpe=sumpe;
		}
	}
	cout<<maxn<<' '<<mp<<' '<<mpe<<endl;
	return 0;
}