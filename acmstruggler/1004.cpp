////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-14 09:34:55
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1004
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1688KB
//////////////////System Comment End//////////////////
#include <map> 
#include <iostream> 
#include <string> 
using namespace std; 
int main() 
{ 
	int n; 
	string str; 
	map<string,int> strMap; 
	while(cin>>n && n) 
	{ 
		strMap.clear(); 
		for(int i = 0; i < n; ++ i) 
		{ 
			cin>>str; 
			int t = strMap[str]; 
			if(t) 
			{ 
				strMap[str] ++; 
			} 
			else 
			{ 
				strMap[str] = 1; 
			} 
		} 
		int nTemp; 
		string strTemp; 
		map<string,int>::const_iterator it = strMap.begin(); 
		nTemp = it->second; 
		strTemp=it->first; 
		while(it != strMap.end()) 
		{ 
			if(it->second > nTemp) 
			{ 
				nTemp = it->second; 
				strTemp = it ->first; 
			} 
			it ++; 
		} 
		cout<<strTemp<<endl; 
	} 
	return 0; 
}