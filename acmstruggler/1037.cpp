////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-15 13:12:57
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1037
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1684KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main(void)
{
	int a[3],i;
	while(cin>>a[0]>>a[1]>>a[2])
	{
		for(i=0;i<3;i++)
			if(a[i]<=168) {cout<<"CRASH "<<a[i]<<endl;break;}
		if(i==3) cout<<" NO CRASH"<<endl;
	}
	return 0;
}