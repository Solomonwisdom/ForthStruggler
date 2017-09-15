////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: acmstruggler
////Nickname: acmstruggler
////Run ID: 
////Submit time: 2015-07-22 15:08:54
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1094
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1684KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main(void)
{
    int a,n,m;
	int sum;
	while(cin>>n){
		sum=0;
		while(n--){
			cin>>a;
			sum+=a;
		}
		cout<<sum<<endl;
	}
    return 0;
}