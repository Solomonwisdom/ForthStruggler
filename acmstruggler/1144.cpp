////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-17 13:04:53
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1144
////Problem Title: 
////Run result: Accept
////Run time:280MS
////Run memory:1676KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string.h>
using namespace std;
int main(void)
{
	int hs,cat,i,c,r,n;
	char cou[100][5],ca[5];
	bool flag;
	while(cin>>hs&&hs)
	{
		cin>>cat;
		for(i=0;i<hs;i++)
			cin>>cou[i];
		flag=true;
		while(cat--){
			cin>>c>>r;
			n=0;
			while(c--){
				cin>>ca;
				if(!flag) continue;
				for(i=0;i<hs;i++)
					if(strcmp(cou[i],ca)==0){
						n++;break;}
			}
			if(n<r) flag=false;
		}
		if(flag) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
	return 0;
}