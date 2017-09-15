////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-17 09:24:25
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1113
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1672KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
string p="******";
map<string,string> m;
bool flag;
int main(void)
{
	string s,t,end="XXXXXX";;
	while(cin>>s&&s!=end)
	{
		t=s;
		sort(s.begin(),s.end());
		m[t]=s;
	}
	while(cin>>s&&s!=end)
	{
		sort(s.begin(),s.end());
		flag=false;
		for(map<string,string>::iterator iter=m.begin();iter!=m.end();iter++)
		{
			if(iter->second==s) {flag=true;cout<<iter->first<<endl;}
		}
		if(!flag) cout<<"NOT A VALID WORD"<<endl;
		cout<<p<<endl;
	}
	return 0;
}