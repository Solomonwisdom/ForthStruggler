////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-22 15:12:45
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1096
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1692KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main(void)
{
    int a;
	int n,sum,m;
	cin>>n;
	while(n--){
		cin>>m;
		sum=0;
		while(m--){
			cin>>a;
			sum+=a;
		}
		cout<<sum<<endl;
		if(n) cout<<endl;
	}
    return 0;
}