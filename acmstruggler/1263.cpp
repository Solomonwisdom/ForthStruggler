////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-25 21:40:05
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1263
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1708KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
#include<map>
using namespace std;
int main(void)
{
	map<string,map<string,int>> xs;
	int n,m,count;
	string fruit,area;
	bool flag=false;
	scanf("%d",&n);
	while(n--){
		if(flag) printf("\n");
		else flag=true;
		scanf("%d",&m);
		while(m--){
			cin>>fruit>>area>>count;
			map<string,map<string,int>>::iterator it=xs.find(area);
			if(it==xs.end()){
				map<string,int> t;
				t[fruit]=count;
				xs[area]=t;
			}
			else{
				map<string,int>::iterator is=it->second.find(fruit);
				if(is==it->second.end())
					it->second[fruit]=count;
				else is->second+=count;
			}
		}
		for(map<string,map<string,int>>::iterator i=xs.begin();i!=xs.end();i++){
			cout<<i->first<<endl;
			for(map<string,int>::iterator j=i->second.begin();j!=i->second.end();j++)
				cout<<"   |----"<<j->first<<'('<<j->second<<')'<<endl;
		}
		xs.clear();
	}
	return 0;
}
