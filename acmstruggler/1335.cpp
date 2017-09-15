////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-20 10:41:30
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1335
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1676KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<iomanip>
#include<string>
#include<map>
using namespace std;
char a[18]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H'};
map<char,int> m;
void transform(string s,int bf,int bt){
	long long b=0,r=1;
	int d;
	string shu="";
	for(int i=s.size()-1;i>=0;i--){
		b+=r*m[s[i]];
		r*=bf;
	}
	while(b>0){
		d=b%bt;
		shu=*(a+d)+shu;
		b=(b-d)/bt;
	}
	if(shu.size()>7) cout<<setw(7)<<"ERROR"<<endl;
	else cout<<setw(7)<<shu<<endl;
}
int main(void){
    string s;
	int bf,bt;
	for(int i=0;i<18;i++) m[a[i]]=i;
	while(cin>>s>>bf>>bt){
		transform(s,bf,bt);
	}
    return 0;
}