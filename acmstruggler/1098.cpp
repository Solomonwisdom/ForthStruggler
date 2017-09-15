////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-16 22:21:47
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1098
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:1688KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main(void)
{
	int i,k;
	while(cin>>k){
		for(i=1;i<=65;i++)
			if((18+i*k)%65==0) break;
		if(i>65) cout<<"no"<<endl;
		else cout<<i<<endl;
	}
	return 0;
}