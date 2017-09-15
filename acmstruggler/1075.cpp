////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-24 11:00:19
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1075
////Problem Title: 
////Run result: Accept
////Run time:1248MS
////Run memory:34016KB
//////////////////System Comment End//////////////////
#include <iostream>
#include<string>
#include<map>
using namespace std;
int main(void)
{
    map<string,string> tras;
	string s1,s2,temp;
	char ch;
	cin>>s1;
	while(cin>>s1&&s1!="END"){
		cin>>s2;
		tras[s2]=s1;
	}
	cin>>s1;
	getchar();
	while(1){
		temp="";
		while(scanf("%c",&ch)!=EOF){
			if(ch=='\n'&&temp=="END") return 0;
			if(ch=='\n') break;
			if(!isalpha(ch)){
				if(tras.find(temp)!=tras.end())
					cout<<tras[temp];
				else cout<<temp;
				cout<<ch;
				temp="";
			}
			else temp+=ch;
		}
		cout<<endl;
	}
    return 0;
}