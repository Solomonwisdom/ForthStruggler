////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-21 13:57:46
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1591
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1660KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string key,line;
	cin>>key;
	for(char c='Z';c>='A';c--){
		if(key.find(c)==string::npos) key+=c;
	}
	getchar();
	while(getline(cin,line)){
		for(int i=0;i<line.size();i++)
			if(isupper(line[i]))
				line[i]='A'+key.find(line[i]);
			else if(islower(line[i]))
				line[i]='a'+key.find(toupper(line[i]));
		cout<<line<<endl;
	}
	return 0;
}