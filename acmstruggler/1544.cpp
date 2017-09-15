////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-21 10:39:45
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1544
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:1676KB
//////////////////System Comment End//////////////////
#include <iostream>
#include<string>
using namespace std;
int main(void)
{
	string s,temp;
	int count,l,r;
	while(cin>>s){
		count=s.size();
		for(int i=1;i<s.size()-1;i++){
			l=i-1;r=i+1;
			while(l>=0&&r<s.size()){
				if(s[l--]==s[r++]) count++;
				else break;
			}
		}
		for(int i=0;i<s.size()-1;i++){
			if(s[i]==s[i+1]){
				count++;
				l=i-1;r=i+2;
				while(l>=0&&r<s.size())
					if(s[l--]==s[r++]) count++;
					else break;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}